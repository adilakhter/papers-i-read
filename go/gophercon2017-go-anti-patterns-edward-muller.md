# GopherCon 2017: Edward Muller - Go Anti-Patterns

- issue https://github.com/at15/papers-i-read/issues/97
- video https://www.youtube.com/watch?v=ltqV6pDKZD8
- source https://medium.com/@copyconstruct/best-of-2017-in-tech-talks-8f78b34ff0b

## Take away

- `internal` package can't be imported by other packages
- `context.Value` escape type system
- don't `panic` in library

## Notes

- go has `internal` package as special name to avoid being imported by other packages https://golang.org/doc/go1.4#internalpackages
- **config structs** hide the complexity
  - use only what you need `doThing(a string, b int)`
  - functional options
`````go
type func(t *Thing) Opt
func WithBar(b string) Opt {
   return func(t *Thing) {
        t.Bar = b
  }
}
`````
- pointer all the things
  - about ownership
  - not necessarily faster (benchmark it)
- `context.Value`
  - escape type system
- Async API
   - use channels internally, don't expose them
   - see stdlib `http` and `buffio.Scanner`
- `if` `then` `else`
  - handle error and return early
  - keep common or happy paths de-dented
- `panic` in lib
  - just return error
  - markup errors with `pkg/errors` to add context before return
- interface all the things (just two struct, one implementation, one for test mock)
  - the bigger the interface, the weaker the abstraction
  - there are other ways for testing except mock
  - don't design upfront, discover later
- naked return (return values are named)
  - don't use it
- `interface{}` says nothing
  - try to make a interface to describe what you need
