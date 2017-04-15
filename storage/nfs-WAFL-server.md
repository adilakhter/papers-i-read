# File System Design for an NFS File Server Appliance

1994 NetApp, Inc.

## Take away

- NFS is a protocol, originally developed by Sun

## Abstract

NetApp, Inc. developed 'a dedicated server whose sole function is to provide NFS file service'

WAFL (Write Anywhere File Layout)

- Snapshots
- copy-on-write
- no need for consistency checking after unclean shutdown thanks to Snapshots
