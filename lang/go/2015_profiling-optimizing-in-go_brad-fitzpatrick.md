# Profiling & Optimizing in Go by Brad Fitzpatrick

- https://www.youtube.com/watch?v=xxDZuPEgbBU
- https://github.com/bradfitz/talk-yapc-asia-2015/blob/master/talk.md

## Take away

- `echo $?` shows exit code of last command
- `runtime.convT2E` is called when using `Printf` due to `args ...interface{}`, all the arguments are converted to interface before passing to the function, which introduce allocation
  - [ ] on heap?
- `testing.TB` https://golang.org/pkg/testing/#TB
- interface is two bytes, one is runtime type, one point to actual data
- blockprofile, not just cpuprofile and memprofile

## TODO

- [ ] it seems convert to interface{} is also related with escape analysis
  - https://www.darkcoding.net/software/go-the-price-of-interface/
  - https://www.ardanlabs.com/blog/2018/01/escape-analysis-flaws.html

## Notes

- a web server, using regular expression
- use `httptest.NewRecorder` in benchmark
- use `-cpuprofile` when bench to generate CPU profile
- use `go tool pprof test.binary profile.file` to enter interactive cli
  - `top`
  - `top --cum`
  - `web` to open the graph in browser
- use `benchcmp` to compare two profile
- `b.ReportAllocs()` inside benchmark
- use `-memprofile` when bench to generate memory profile
   - in pprof `list methodname`
   - `disasm`

Optimizations

- use `regexp.Compile`
- use `fmt.Fprintf` instead of []byte(str1 + str2) for w.Write()
- use buffer pool
- use `buf.WriteString` instead of `fmt.Sprintf` because arguments need to be converted to interface{}, which causes `runtime.convT2E`
