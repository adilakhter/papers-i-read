# Time Series Database Lectures from CMU DB - Heron

- issue https://github.com/at15/papers-i-read/issues/74
- video https://www.youtube.com/watch?v=jCswlLsE3No
- from http://db.cs.cmu.edu/seminar2017/

## Take away

- auto pilot stream processing https://blog.acolyer.org/2017/06/30/dhalion-self-regulating-stream-processing-in-heron/
- a replacement of storm https://github.com/at15/papers-i-read/issues/27

## Notes

- structure
  - dag execution plan
 - spout (incoming data, Kafka, MySQL)
  - bolt (exectuor), (sounds like Storm a lot ...)
  - scheduler (use external)
- topology components
  - topology master
  - data container
    - stream manager (routing data)
    - metrics manager (trouble shooting)
    - I_1 ... I_n the real executors
  - sync with ZK about logical plan, physical plan, execution state
- backpressure
- UI
- load variation
  - spike
  - daily patterns
- auto pilot (self)
   - tuning
   - stabilizing
   - healing
- auto pilot -> Dhalion (from MS)
   - https://blog.acolyer.org/2017/06/30/dhalion-self-regulating-stream-processing-in-heron/
   - https://github.com/Microsoft/Dhalion
