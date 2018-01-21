# The Case for Learned Index Structures

## Abstract

- all existing index structure can be replaced other type of models, including deep learning models
  - call it **learned index**
- outperform B-Tree by up to 70% and save memory in real world dataset

## Introduction

- different index for different access pattern
- B-Tree index, range
- Hashmap index, key-based
- Bloom-filters, existence
- *general, can't handle worst case* in real world data
- knowing exact data distribution allow highly optimized (specialized) index
  - machine learning can make this specialization automated, low engineering cause
- index are like models
  - B-Tree is a model that takes a key and produce a location in data record
  - Bloom-Filter is a binary classifier
- GPU, TPU make neural network operations cheap while CPU does not have much potential
- focus on read only analytical workload, but also consider sorting, joins
- all sections contain evaluation and open challenge
