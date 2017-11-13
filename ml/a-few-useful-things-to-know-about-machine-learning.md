# A Few Useful Things to Know about Machine Learning

https://homes.cs.washington.edu/~pedrod/papers/cacm12.pdf

> Developing successful machine learning applications requires a substantial
amount of "black art" that is hard to find in textbooks.

so they summarize 12 key lessons (hmm, reminds me of 12 factor app)

## 1. Introduction

- much folk knowledge is not in text book, but easy to communicate
- take classification as example

## 2. Learning = Representation + Evaluation + Optimization

Representation

- hypothesis space of the learner

Evaluation

> the evaluation function used internally by the algorithm may differ from the
external one that we want the classifier to optimize, for ease of optimization

Optimization

- combinatorial optimization
- continuous optimization

## 3. It's generalization that counts

> The fundamental goal of machine learning is to generalize beyond the examples in the training set

- set some of the data aside from the beginning, and only use it to test your chosen classifier at the very end
- learn your final classifier on the whole data
- use cross validation for parameter tunning
- don't have access to the function want to optimize, have to use training error as surrogate for test error

## 4. Data alone is not enough

- data alone is not enough, no matter how much of it you have
- every learner must embody some knowledge or assumptions beyond the data it's given in order to generalize beyond it
- "no free lunch theorem", no learner can beat random guessing over all possible functions to be learned

> We have dubbed the associated results NFL theorems because they demonstrate that if an algorithm performs well on a certain class of problems then it necessarily pays for that with degraded performance on the set of all remaining problems

- luckily, this is not the case in real world
- when choosing a representation, one key criteria is which kinds of knowledge are easily expressed in it

> Learning is more like farming, which lets nature do most of the work.
Farmers combine seeds with nutrients to grow crops. Learners combine knowledge with data to grow programs

## 5. Overfitting has many faces

- bias, consistently learn the same wrong thing
- variance, learn random things irrespective of the real signal

> contrary to intuition, a more powerful learner is not necessarily better than a less powerful one

> strong false assumptions can be better than weak true ones, because a learner with the latter needs more data to avoid overfitting

**cross validation itself can overfit**

- it's easy to avoid overfitting (variance) by falling into the opposite error of underfitting (bias)
- server overfitting can occur even in the absence of noise

## 6. Intuition fails in high dimensions

- after overfitting, the biggest problem in machine learning is the *curse of dimensionality*
- what works in low dimension no longer work in high dimension
- our intuitions, which comes from a 3-D world, often do not apply in high-dimensional ones
- one may think more features never hurts, but in fact their benefits may be outweighted by the curse of dimensionality
- 'blessing of non-uniformity', in most applications examples are not spread uniformly throughout the instance space, but are concentrated on or near a lower-dimensional manifold.

## 7. Theoretical guarantees are not what they seem

- if learner A is better than learner B given infinite data, B is often better than A given finite data

> The main role of theoretical guarantees in machine learning is not as a criterion for practical decisions,
but as a source of understanding and driving force for algorithm design. In this capacity, they are quite useful;
indeed, the close interplay of the theory and practice is one of the main reasons machine learning has made so
much progress over the years. But caveat emptor. learning is a complex phenomenon, and just because a learner has a
theoretical justification and works in practice doesn't mean the former is the reason for the latter.

## 8. Feature engineering is the key

- some succeed and some fail, the most import factor is the feature used

> This is typically where most of the effort in a machine learning project goes.
It is often also one of the most interesting parts, where intuition, creativity and "black art" are as important as the technical stuff

- feature engineering is more difficult because it's domain-specific, while learners
can be largely general-purpose

## 9. More data beats a clever algorithm

- **it pays to try the simplest learners first** (e.g. naive Bayes before logistic regression)
- two types:
  - representation has a fixed size, i.e. linear classifier
  - grow with data, i.e. decision tree
- **the biggest bottleneck is not data or CPU cycles, but human cycles**

## 10. Learn many models, not just one

- model ensemble
  - simplest called bagging, generate random variations of the training set by resampling, learn
a classifier on each, and combine the results by voting
  - boosting, each new classifier focuses on the examples the previous one tended to get wrong
  - stacking
- ensemble != BMA (Bayesian model averaging)

## 11. Simplicity does not imply accuracy

- simple is better because it's simple, not higher accuracy
- counter example
  - model ensemble
  - SVM, have infinite number of parameters without overfitting

## 12. Representable does not imply learnable

## 13. Correlation does not imply causation

- correlation is a sign of a potential causal connection, and we can use it as a guide to further investigation

## 14. Conclusion
