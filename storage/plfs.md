# PLFS: A Checkpoint Filesystem for Parallel Applications

- https://github.com/plfs/plfs-core
- checkpoint is widely used for HPC, thousands processes need to store their state
so they can restart from latest when crashed
- N-N, each process write to different files
- N-1, write to a shared file
  - fragmented (rare)
  - stride (common)
- existing
  - ZEST, similar philosophy, but some disks are idle
  - Lustre Split Writing, require code change and limit to Lustre
  - PanFS, GPFS, poorly for N-1
- PLFS, based on FUSE
  - create a directory when create a shared log file
  - create different files for different process
  - index file for faster lookup
  - index file merged into lookup table
- order of magnitude faster
