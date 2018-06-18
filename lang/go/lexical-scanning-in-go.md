# Lexical Scanning in Go

- https://talks.golang.org/2011/lex.slide#1
- want a real lexer and parser for go's template

[lex item](https://talks.golang.org/2011/lex.slide#8)

````go
const (
  itemError itemType = iota
  itemDot
  itemEOF
  itemElse
  itemLeftMeta // {{
)
// item is token
type item struct {
  type itemType
  val string // i.e. "23.2"
}
````

traditionally state machine

````go
switch state {
case state1:
    state = action1()
case state2:
    state = action2()
}
````

now use state func
