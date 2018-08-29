# Go 2 proposal on error handling and generic

- issue: https://github.com/at15/papers-i-read/issues/117
- source: https://go.googlesource.com/proposal/+/master/design/go2draft.md

## Take away

- existing go 1 code will still work
- go's error handling will remain explicit, will have (syntax sugar?) to allow handle multiple errors in one place
- error will allow wrapping like https://github.com/pkg/errors, use `Is` for exact match and `As` for type based match in error chain

## My thoughts

- no things like `ErrorCode()`, compare string is similar to compare int in some sense though ...
- user still can/have to define their own error struct to attach additional information
- there is no intention to categorize application level error, i.e. IOExeception, InvalideParameterException
  - it would make error collecting and automated trouble shooting system much easier
- some effort is spent on printing error in a localized format, maybe it's better done by application,
if you print error in terminal, people using it is likely to have basic understanding of English.
If you write a web application, there is no reason to print the full call stack of a error when
user just want to order a cup of coffee.

## Error Handling - Problem Overview

Problem

| language | error result   | error check | example |
| :------- | :------------- | :---------- | :---- |
| go | explicit  | explicit | if err := json.Unmarshal(b, p); err != nil { <br> &nbsp;&nbsp; return errors.Wrap(err, "error decode json") <br> }|
| C | explicit | implicit | if (foo() == -1) { <br> &nbsp;&nbsp;  if (errno == ...) {...}; <br> } |
| Java | implicit | implicit | throw new IOExeception("I got a feeling"); |

- it's good to be explicit, but user will get tired of it

Goals

> Both error checks and error handling must remain explicit, meaning visible in the program text. We do not want to repeat the pitfalls of exception handling.

> Existing code must keep working and remain as valid as it is today. Any changes must interoperate with existing code.

Design

- use `handle` and `check`, if `check` fail, it will find closest `handle` to handle the error
  - It really feels like a syntax sugar where `defer + recover = handle` and `check = panic(err)`

````go
func main() {
	handle err {
		log.Fatal(err)
	}

	hex := check ioutil.ReadAll(os.Stdin)
	data := check parseHexdump(string(hex))
	os.Stdout.Write(data)
}
````

Other language

- Rust: rely on Generic (returns a Option<Value, Error>)
- Swift: although there are `throw` `catch`, they are syntax for explicit error handling

## Error Values - Problem Overview

Problem

### Four ways of error handling

- compare equality with sentinel errors like `io.EOF`
- using type assertion or type switch, i.e. `dbErr, ok := err.(DBError)`
- ad-hoc check like `os.IsNotExist` doing limited unwrapping
- substring search with `err.Error()`

Example, an RPC call that failed to open `/etc/resolv.conf` due to permission error

> There are many questions you might want to ask programmatically of err, including: (i) is it an RPCError? (ii) is it a net.OpError? (iii) does it satisfy the net.Error interface? (iv) is it an os.PathError? (v) is it a permission error?

- func like `os.IsExist` is not generic enough and can't handle wrapped error
- 'deeply nested errors is too difficult to read and leaves no room for additional detail, like relevant file positions in the program'

### Goals of Error Values

- make error inspection less error prone
- print errors with additional detail in a standard form

Error handling should be cheap

> As a cautionary tale, years ago at Google a program written in an exception-based language was found to be spending all its time generating exceptions. It turned out that a function on a deeply-nested stack was attempting to open each of a fixed list of file paths, to find a configuration file. Each failed open operation threw an exception; the generation of that exception spent a lot of time recording the very deep execution stack; and then the caller discarded all that work and continued around its loop. The generation of an error in Go code must remain a fixed cost, regardless of stack depth or other context. (In a panic, deferred handlers run before stack unwinding for the same reason: so that handlers that do care about the stack context can inspect the live stack, without an expensive snapshot operation.)

### Draft Design of Error Values

````go
package errors

type Wrapper interface {
	Unwrap() error
}

func (e *WriteError) Unwrap() error { return e.Err }

// Is reports whether err or any of the errors in its chain is equal to target.
func Is(err, target error) bool {}

// As checks whether err or any of the errors in its chain is a value of type E.
// If so, it returns the discovered value of type E, with ok set to true.
// If not, it returns the zero value of type E, with ok set to false.
func As(type E)(err error) (e E, ok bool) {}
````

- [ ] TODO: Note that the second function has a type parameter, using the contracts draft design.

## Ref
