# Virtualizing Disk Performance

2008, UCSC

## Ref

- Virtualizing Disk Performance with Fahrrad https://www.usenix.org/legacy/event/fast08/wips_posters/povzner-wip.pdf
- Zygaria: Storage performance as a managed resource. https://www.researchgate.net/publication/4233091_Zygaria_Storage_Performance_as_a_Managed_Resource
  - is based on this system and replace IOPS with throughput

## Take away

- disk time utilization is independent of workload, make it better for virtual disk scheduler than throughput
- 'Always bear in mind that the real measure of computer performance is time' Computer Architecture: A Quantitative Approach

## TODO

- [ ] is it similar to time slicing in CPU scheduling
- [ ] are people using machine learning for scheduling
  - [ ] PHP compile optimization, Profile-Guided Optimization
- [ ] amazon is guaranteeing IOPS I guess? (It only says Max, clever ....)
  - https://aws.amazon.com/ebs/details/#VolumeTypes
  - [ ] AWS use number of I/O requests like old Zygaria
- [ ] a scheduler for multiple virtual disk? or physical disk? a physical disk has multiple virtual disk that used by different application
- [ ] it's actually not independent from workload, it's you adapt to workload
- [ ] which layer exactly for Zygaria, on top of an existing block device
- [ ] why in experiment, each virtual device can only run one type of workload, what would happen if I run mixed workload on each virtual device
- [ ] 4.3 util random service time: but 300u is same and didn't make much difference ....?
- [ ] since the throughput-based has lower overall throughput, it has a lot of idle time due to scheduling?
  - [ ] and if it use a open loop arrival, at the end of the experiment, there are many outstanding requests in the queue?

## Introduction

- [OLD] guarantee storage performance for mixed workloads has little successful research
- reserve **disk performance** from application, guaranteed by system
  - NOTE: not disk space, which can be achieved using https://linux.die.net/man/3/posix_fallocate
- require a uniform representation of disk performance
- [OLD] disk throughput has traditionally been used to describe storage system performance, BUT
  - disk requests are stateful: heavily depend on the location of immediately preceding request
  - partially non-deterministic: remapping, re-calibration, impossible to determine a priori
  - disk requests are non-preemptible (可抢占): once issued, must be allowed to finish
  - huge difference between best- and worst-case request times: depend heavy on application I/O behavior
- [OLD]? reserve performance based on worst request time
  - one 1% of max performance

**virtual disk and guaranteeing performance in a shared storage system requires isolating each application from the behavior of others**

- [ ] each request stream must be correctly charged for its seek behavior in order to avoid interfering with the performance of other streams
- **disk time utilization**: time spent servicing I/O requests, analogous to CPU utilization - is **the appropriate basis for managing disk performance**
  - a quantity we can actually guarantee without losing most of our performance
  - charge each stream for the disk seeks it incurs, allowing isolation between request streams
  - a virtual disk comprising a time share of the actual disk can be
    - requested
    - verified
    - guaranteed without any assumptions about application behavior
- disk time utilization is the only workload independent way of expressing and managing disk performance

**provide virtual disks with a utilization-based disk scheduler and compare it to a throughput-based approach**

## 2. Virtual disks based on utilization

Virtual disk is a fractional share of a disk whose performance depends only upon
- its workload
- its share
- the best performance of the device
- [ ] no other applications sharing the same physical disk
  - > the performance of a virtual disk should be independent of the performance or behavior of any other
- [OLD] I/O rate one can not exploit the increased efficiency of well-behaved streams as the guaranteeble performance is constant and must be based on worst-case

### 2.1 Measuring and guaranteeing utilization

- single queue/single server model
- [ ] in units of u seconds of execution per seconds
- need extension for multiple-server queuing systems like RAID
- use estimation
  - based on history
  - has lag

I/O scheduler decides which I/O request to send to the disk for service. based on
- what requests are enqueued and can be chosen for service
- how each virtual device is doing with respect to its reservation
- estimated utilization needed for each pending request
  - [ ] isn't it related with workload?

Life Cycle of an I/O request
- scheduling
- execution
- completion

Three Questions
- how to estimate execution time
- actual execution time
- avoid unstable behavior when workloads change abruptly

Estimate
- sequential: small constant value
- other: safe value (average of random I/O)
- correct based on measured

Use *token bucket* to track

Cope with abrupt changes in the offered load

### 2.2 Providing isolation

Five guarantee

- guarantee to each virtual device the utilization it has reserved
- [ ] account for all seeks and other delays
- charge each virtual device for the time spent on each of its request
- sufficiently coarse granularity that inter-stream seeks are minimized
- [ ] any cost of the remaining inter-stream seeks is randomly distributed across the active virtual disks

### 2.3 Admission Control

admit or deny request for new virtual disks or change in virtual disk parameters

### 2.4 Translating application requirement

- allow soft performance guarantees in term of throughput
- based on seek time, rotation time, transfer rate, calculate utilization time based on I/O rates

## 3. Implementation

- virtual disk driver based on previous Zygaria, replace NO. I/O requests based with execution time measured in u seconds
- Linux kernel module layered on top of an existing block device
  - [ ] which layer exactly
- two token bucket
  - reserve: guaranteed share of disk time
  - limit: caps the use of unclaimed resources
- based on a weighted moving average of each virtual device over the last few seconds the scheduler determines which device should get scheduled
- the scheduling algorithm determines which I/O request to schedule next as follows
  - eliminate device reach/above limit or not requests
  - EDF (earliest dead line first) scheduling:
    - which device has the earlies deadline
    - select the virtual device with the lowest usage
- when a virtual device is selected, its I/O request is sent to the low-level device driver the **accounting** for the virtual device is updated to reflect the request
- [OLD] need correction after the request is finished (if using I/O requests number, this is not needed)
- sequential requests typically execute in less than 10 u sec, while random requests typically take around 15 msec
  - **the scheduler should charge the same amount of estimated execution for more than 1500 sequential operations as for one random operation**
- [OLD] estimate execution time
  - in device driver, generate detailed, accurate predictions
  - various machine learning techniques
- split into sequential and random
  - sequential (< 100 sectors from the previous request): 300 u seconds
  - random 20ms

## 4. Evaluation

Compare utilization-based with previous throughput-based Zygaria
- performance guarantee
- isolation

Arguments

- 4.3 utilization is better than throughput
- 4.4 utilization is less sensitive
- [ ] 4.5 time-varying properties of utilization-based scheduler

### 4.1 Environment Setup

- [ ] TODO: the disk was used as an unmounted raw device dedicated to the experiments.

Workload

- Pharos, random or sequential I/O streams of 4 KB requests with different arrival pattern
  - open-loop: constant interarrival time
  - closed-loop: constant thinking time and fixed number of outstanding requests

Utilization is reserved by virtual devices which serve stream of I/O requests

### 4.2 Controlling Performance

utilization-based vs throughput-based

Two virtual devices together reserving all reservable resources of the disk
- serve sequential requests
- serve random requests

Throughput reservations are fulfillable but provide poor control over the division of performance and lower overall performance

- [ ] why figure 5(a) the percent is from 0 - 1000 instead of 100
- [ ] throughput-based scheduler allows only a small fraction of the I/O rate to be controllered by reservation,
the rest is determined by the scheduler's slack management policy.
- a sequential stream reserving 10% or more received far more than its reserved throughput - more, in fact, than the total reservable throughput
- [OLD] increasing the sequential reservation did not result in an increasing share of the achieved throughput
- figure 6, utilization-based approach max throughput as its reservation increased
- [ ] under the throughput-based scheduler, it was capped by the reservation, which was in turn capped by the maximum guaranteeable throughput
  - [ ] why it can't approach max when you have reserved all throughput, because you reserve reservable, which is 10% in worst case?

### 4.3 Sensitivity to model errors

utilization-based
- sequential time
- random time
- seq or random?
  - [ ] TODO: they didn't say how they distinguish seq and random? by distance of sector? yes, 100 TODO: search above, must have noted it

throughput-based
- nominal (maximum reservable) I/O rate as its model

utilization (underestimate) random service time  
- **as long as there is a significant difference** between the sequential and random estimates, the scheduler will behave correctly
  - [x] the last one, use 300 u seconds for both sequential and random but why the result is similar, the limit of queue?
  - ! this only change the random service time, from 20m -> 5m -> 300u
  - [ ] but 300u is same and didn't make much difference ....?

utilization (overestimate) sequential service time
- each request stream received the utilization it reserved, regardless of overestimates in the sequential request service time
- [ ] didn't try 20m while random tried 300u

Throughput
- figure 9 very sensitive
- [ ] why can't they change the legend when the most part is empty
- overestimate in reservable throughput the random stream does not achieve 100% of its reservation - as expected

### 4.4 Shor-term behavior

- the scheduler gives multiple virtual devices their proper utilization when the workload is stable
- responds properly when the workload changes

Three key effects

- each stream receive at least the performance reserved by its device or fair share after transients(短暂的) due to workload changes
- when a stream begin sending requests, it briefly receives more than its usual performance because its bucket accumulate tokens (up to one second worth
  of its reservation)
- when a stream stops sending requests there is another stream will briefly get more

**This is a general problem in feedback control system**

## 5. Related work

**Storage virtualization**

- capacity
- performance

Distributed systems
- stonehenge, use bandwidth
- parallax large number of virtual machine images
- storage tank
- sleds
- facade

Individual storage servers
- Argon
- Fahrrad: hard performance guarantee

**Application requirements and behavior**

Three different approaches based on application requirement and behavior

- application requirements can be used to assign to specific storage devices
  - [ ] project ideas, blue store, ssd, hdd, use different key name
- dynamically changing the share of storage performance given to each application to control request latency
- directly use application metrics to control I/O scheduling

**Scheduling and Metrics**

- [OLD] overall efficiency
- throughput (similar to bandwidth and I/O rate)
- response time (similar to latency)

**Isolation**

- difficult, little research

## 6. Conclusion

- Bandwidth is a poor basis for performance reservation
- Disk time utilization is a more effective basis

This section can be used to answer the review questions directly ....
