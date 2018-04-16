# WD: A Tail of Latency, IOPS, & IO Priority

- why priority to the device is important
- what they did to get priority to the device
- results

## Take away

- Linux Storage Stack Diagram https://www.thomas-krenn.com/de/wikiDE/images/e/e0/Linux-storage-stack-diagram_v4.10.png

## Terms

- IOPS: Input/output operations per second
- QD: Queue Depth
- https://blog.docbert.org/queue-depth-iops-and-latency/
  - more thread, more IOPS
  - until hit HBA Queue Depth
  - effective queue depth is the actual queue depth times the number of paths
    - host multipathing, where there are multiple paths to each physical LUN. Multipathing is done at the OS level, so from the HBA perspective each of the paths to a LUN is a unique LUN - which means that the number of outstanding IO's across those paths is additive for each path to the LUN.
- HBA: Host bus adapter connects a computer, which acts as the host system, to other network and storage devices
- actuator: 制动器
- peripheral: 外围设备
- Linux IO scheduler http://stackoverflow.com/questions/1009577/selecting-a-linux-i-o-scheduler
  - noop: memory, flash
  - deadline: a light weight scheduler which tries to put a hard limit on latency
  - cfq: tries to maintain system-wide fairness of I/O bandwidth
    - time slicing?
- NVMe: NVM Express (NVMe) or Non-Volatile Memory Host Controller Interface Specification (NVMHCI) is a logical device interface specification for accessing non-volatile storage media attached via a PCI Express (PCIe) bus
- Libata

## TODO

- The Tail at Scale by Jeff Dean https://research.google.com/pubs/pub40801.html
- [x] sure it's Tail instead of Tale? Yes, better tail latency
- [ ] kernel scheduler process based or thread based?
- [ ] didn't see much about tail latency

## Introduction

- 12TB 7200 RPM HDD
- 243 MB/s
- IOPs 200 4k? Rand Read IOPs at QD 32
  - queue depth
- single actuator arm
- better tail latency - lets work together?
  - [ ] let HDD work together with OS and/or application?
- support NCQ Priority

Linux

- support IOPriority
- not passed to the drive
- not so fast
- used for one particular block scheduler
  - `/sys/block/sda/queue/scheduler`

## Handle Priority

- Block layer
  - priority no longer exists when it makes to device
  - device may have large queue
  - implemented by time slicing
- Device
  - block layer scheduler irrelevant?
    - Hints of this with NVMe?
  - [ ] FW?

SATA Native Command Queuing

- [ ] don't quite get the graph

Linux Currently

- [ ] User Space IO Converted to BIO in Kernel
- for CFQ scheduler only

## What, Why, How

- Pass to the drive
  - all scheduler
- Drive level priority should enable finer grained control
  - respect high level priority IO in device queue
- Grab priority from IO context
- Libata (**area of kernel modified**)
  - recognize IO priority in SCSI command and build SATA command with priority information

## Future

- How does this work translate to distributed storage systems
- Will this be mapped onto NVMe devices using prioritized queues or using prioritized commands
  - [ ] what's the different between queue and command?
