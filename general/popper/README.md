# Popper: Making Reproducible Systems Performance Evaluation Pratical

I wanted to put the notes in Mendeley but it got sync file problem again ... Bugdeley

- https://www.soe.ucsc.edu/sites/default/files/technical-reports/UCSC-SOE-16-10.pdf

## Abstract

It basically talking about how to use DevOps tools to make research reproducible,
like using Ansible to setup the environment, and keep experinment data in the VCS
with the configuration.

## Points in doubt

- for system research, Virtual Machine has too much performance lost, but using
OS-Level virtualization like docker, this problem can be solved.
- use `git-lfs` for large file, I don't think storing dataset in plain file in VCS
is better than storing in database. i.e. time series database as I mentioned in Xephon-B's
paper draft.

## Facts

- > For experinments that cannot run on consolidated infrastructures due to noisy-neighborhood
phenomena, bare-metal as a service is an alternative
- > Github projects can have a DOI associated with it,
which is one of the main reasons we use it as our VCS service

## Important facts

- > [Cloudlab](https://www.cloudlab.us/), [Chameleon](https://www.chameleoncloud.org/) and [PRObE](https://www.nmc-probe.org/)
are NSF-sponsored infrastructures for research on cloud computing that allow users to easily provision bare-metal machines to
execute multi-node experinments.
- Found [YCSB++](http://www.pdl.cmu.edu/ycsb++/) when looking at PRObE.
- > Current parctices in the Systems Research community don't include either controlled or statistical
reproducibility experinments. Instead, people run several executions (usually 10) on the same machine and report
averages. Our research focues in looking at the challenges of providing controlled
environments by leveraging OS-level virtualization. [28] reports some preliminary work.

## Interesting facts

- HPC, traditionally, setup is managed by ad-hoc bash script
- use JupyterNotebook for render data and graph

## TODO

- what is **regression testing** mentioned in the paper, it could be a support
for Xephon-B, cause the benchmark tool wants to aid database developers.
- > The output can be in any format (CSVs, HDF, NetCDF, etc.)
- > We execute baseliner on multi-node setiups and make the profiles part of the results
since this is the fingerprint of our execution.
