# Intro to Apache Spark for Java and Scala Developers

- https://www.youtube.com/watch?v=x8xXXqvhZq8
- https://github.com/at15/papers-i-read/issues/14

- DAG
- [ ] Flume Java, run and test in local machine but run in cluster when production, could be useful for Xephon-B, like when debug, run in one thread, etc. Though Xephon-B should really be able to run on multiple servers to create large workload
- Skew problem, workload goes to one core because of underlying data distribution,
  - add salt to key so they are distributed more evenly
- Cartesian Join
  - Nested Structures
  - Windowing
  - ReduceByKey
- Repartitioning
