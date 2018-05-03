# Go Walkthrough: encoding/json package

https://medium.com/go-walkthrough/go-walkthrough-encoding-json-package-9681d1d37a8f


## TODO

- [ ] JSON is LL(1) parseable

## Encoding

Two methods

- [json.Encoder](https://golang.org/pkg/encoding/json/#Encoder) stream in data and strem out to `io.Writer`
- [json.Marshal](https://golang.org/pkg/encoding/json/#Marshal)

Process

- use reflect to get type
- use builtin encoder or build on the fly by inspecting struct using reflect
  - [ ] TODO: how to cache encoder built on the fly
    - use `reflect.Type` as key and function as value in a map?
- check `json.Marshaler`
- check `encoding.TextMarshaler`
  - used for `time.Time`
- tags
  - `string` forces a field to encode as a string
- written to internal buffer called `encodeState`
  - encoder use a pool
- return bytes or write to writer

````go
// json/encode.go

func Marshal(v interface{}) ([]byte, error) {
	e := &encodeState{}
	err := e.marshal(v, encOpts{escapeHTML: true})
	if err != nil {
		return nil, err
	}
	return e.Bytes(), nil
}


// An encodeState encodes JSON into a bytes.Buffer.
type encodeState struct {
	bytes.Buffer // accumulated output
	scratch      [64]byte
}

func newEncodeState() *encodeState {
	if v := encodeStatePool.Get(); v != nil {
		e := v.(*encodeState)
		e.Reset()
		return e
	}
	return new(encodeState)
}

// json/stream.go
// An Encoder writes JSON values to an output stream.
type Encoder struct {
	w          io.Writer
	err        error
	escapeHTML bool

	indentBuf    *bytes.Buffer
	indentPrefix string
	indentValue  string
}

func (enc *Encoder) Encode(v interface{}) error {
	if enc.err != nil {
		return enc.err
	}
	e := newEncodeState()
	err := e.marshal(v, encOpts{escapeHTML: enc.escapeHTML})
	if err != nil {
		return err
	}
	// Terminate each value with a newline.
	e.WriteByte('\n')
	b := e.Bytes()
  // NOTE: code for handling indent are omitted
	if _, err = enc.w.Write(b); err != nil {
		enc.err = err
	}
	encodeStatePool.Put(e)
	return err
}
````

## Decode

Two methods

- [json.Decoder](https://golang.org/pkg/encoding/json/#Decoder)
- [json.Unmarshal](https://golang.org/pkg/encoding/json/#Unmarshal)

Process

- scanner
  - JSON is LL(1) parseable, just need to look ahead one byte, i.e. `{` means a object, `[` means an array, `"` means a string
  - stack is used to handle nested structure
- decoders are not cached
- check `json.Unmarshaler` and `encoding.TextUnmarshaler`

> This phase of matching tokens to values involves heavy use of the reflect package, however, these decoders are not cached so reflection has to be redone on every decode

## Pretty printing

- [json.Indent](https://golang.org/pkg/encoding/json/#Indent)
- [json.Compact](https://golang.org/pkg/encoding/json/#Compact)

## Extra

Stuff added by @at15

- string encoder will escape string
- there is two version, one for string, one for `[]byte` ... guess they did that for speed ...

````go

// NOTE: keep in sync with stringBytes below.
func (e *encodeState) string(s string, escapeHTML bool) {
	e.WriteByte('"')
	start := 0
	for i := 0; i < len(s); {
		if b := s[i]; b < utf8.RuneSelf {
			if htmlSafeSet[b] || (!escapeHTML && safeSet[b]) {
				i++
				continue
			}
			if start < i {
				e.WriteString(s[start:i])
			}
			switch b {
			case '\\', '"':
				e.WriteByte('\\')
				e.WriteByte(b)
			case '\n':
				e.WriteByte('\\')
				e.WriteByte('n')
			case '\r':
				e.WriteByte('\\')
				e.WriteByte('r')
			case '\t':
				e.WriteByte('\\')
				e.WriteByte('t')
			default:
				// This encodes bytes < 0x20 except for \t, \n and \r.
				// If escapeHTML is set, it also escapes <, >, and &
				// because they can lead to security holes when
				// user-controlled strings are rendered into JSON
				// and served to some browsers.
				e.WriteString(`\u00`)
				e.WriteByte(hex[b>>4])
				e.WriteByte(hex[b&0xF])
			}
			i++
			start = i
			continue
		}
		c, size := utf8.DecodeRuneInString(s[i:])
		if c == utf8.RuneError && size == 1 {
			if start < i {
				e.WriteString(s[start:i])
			}
			e.WriteString(`\ufffd`)
			i += size
			start = i
			continue
		}
		// U+2028 is LINE SEPARATOR.
		// U+2029 is PARAGRAPH SEPARATOR.
		// They are both technically valid characters in JSON strings,
		// but don't work in JSONP, which has to be evaluated as JavaScript,
		// and can lead to security holes there. It is valid JSON to
		// escape them, so we do so unconditionally.
		// See http://timelessrepo.com/json-isnt-a-javascript-subset for discussion.
		if c == '\u2028' || c == '\u2029' {
			if start < i {
				e.WriteString(s[start:i])
			}
			e.WriteString(`\u202`)
			e.WriteByte(hex[c&0xF])
			i += size
			start = i
			continue
		}
		i += size
	}
	if start < len(s) {
		e.WriteString(s[start:])
	}
	e.WriteByte('"')
}
````