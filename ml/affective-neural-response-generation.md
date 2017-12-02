# Affective Neural Response Generation

## Introduction

- embed word with affective (cognitively engineered?)
  - [Norms of valence, arousal, and dominance for 13,915 English lemmas](https://link.springer.com/article/10.3758/s13428-012-0314-x)
- augment cross-entropy loss with affective
- affectively diverse beam search

## Related Work

- retrieval-based or slot based spoken dialogue system
- Affect-LM, binary affective features, positive and negative
- Emotional Chatting Machine, requires input of desired emotion

## Background

### Word Embeddings

- map words (or tokens) to real-valued vectors of fixed dimensionality
  - i.e. Word2Vec
- co-occurrence statistics are insufficient to capture sentiment/emotional features

### Seq2Seq Model

- seq2seq model is an encoder decoder neural framework that maps a variable length input sequence to a variable length output sequence
  - encoder, RNN w/ LSTM
  - decoder, RNN w/ LSTM
- train
  - cross entropy loss (XENT)?
- prediction
  - generate a response Y to a prompt X by computing `argmaxY{logp(Y|X)}`
    - greedily
    - variants of beam search

## The Proposed Affective Approaches

### Affective Word Embeddings

- an external cognitively-engineered affective dictionary
- 13, 915 lemmatized English words, three dimensions of emotions
  - Valence: V, the pleasantness of a stimulus (刺激)
  - Arousal: A, the intensity of emotion produced, or the degree of arousal evoked, by a stimulus
  - Dominance: D, the degree if power/control exerted by a stimulus
  - http://crr.ugent.be/archives/1003
- first to introduce VAD to dialogue generation
- directly take as 3-dimensional word-level affective embeddings
  - [ ] so just 3-d for word embedding?
- [ ] TODO: how to do the visualization? using t-NSE like word embedding?
- use neutral vector [5, 1, 5] for stop words and proper nouns
- concatenate W2AV embeddings of each word with its traditional word embeddings, as input for both encoder and decoder
