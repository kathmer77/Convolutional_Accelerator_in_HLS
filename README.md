# Convolutional_Accelerator_in_HLS

<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066015-105a76cd-94fe-4b1f-b5b0-9ea4993c2139.png" width="800" height="250"/>
</p>


The Transformer model is a neural network that aims to solve sequence-to-sequence tasks, such as natural language tests, genome sequences and sound signals among other data. 
Mostly used for Natural Language Processing (NLP) and Computer Vision (CV) applications. Proposed in "Attention is All You Need” by Google in 2017.

The overall architecture of the Transformer involves an encoder block on the left, and a decoder block on the right. 
Both encoder and decoder consist of Multi-Head Attention and Feed Forward layers. These blocks, can be stacked on top of each other multiple times, 
which is indicated by Nx. In broad terms, The Transformer takes an input sentence in the form of a sequence of vectors and translate these into an “encoding vector”, 
which is decoded back into another different sequence.

<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066554-12898cb9-d77e-43ef-80e6-6e3c0a824c5a.png" width="300" height="350"/>
</p>

## Project Description

This project aims to create an HLS implementation of the important layers of the Transformer architecture and explore the effects of optimization on FPGA resources utilization and latency. 
The effort is focused on implementing the scaled-dot-product and multi-head attention layers, along with normalization and linear layers that form the building block of 
many sub-layers throughout the architecture. 
It has been used a “from-scratch” implementation of the model instead of one using high level built-in classes, 
so that, I could examine and build individual layers in HLS using the functionality described in the Pytorch as a guide. 
This was also helpful in debugging the outputs of individual layers as I built them in HLS.

### Attention Mechanism

The heart of the Transformer is the incorporation of the Attention Mechanism. Attention is a means of selectively weighting different elements in the input data, 
so that they will have an impact on the remaining layers. In other words, this mechanism indicates in which parts of the input vector the network should focus on 
in order to generate the output vector. For instance, in translation, the word “it” can be translated into Spanish or French using the correct gender because the attention mechanism put the spotlight 
in all the relevant words in the original sentence.

<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066664-8c21ad8c-6d62-4c6b-8329-44dded4fa5e7.png" width="370" height="300"/>
</p>

### Computation 


The implementation consists of converting input data into “Key, Query and Value" vectors. 

Considering the translation example: Q is the matrix that contains the Query, 
vector representation of one word in the sequence. K are all the Key vectors representing all the words in the sequence. 
Finally, V is the matrix of the values, which is also, the vector representations of all the words in the sequence. 
The dot product of the key and query provide the attention weight. Meaning, how much focus should a word be put with respect to other words.
For this project, I have defined this as the “Score Matrix”. This matrix is squashed using a “Softmax” function so that all attention weights will have a total weighting of 1. 
The value of vectors is multiplied by the result of the latter, before being fed into subsequent layers.



<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066783-ce57483a-026d-4d00-b2a5-1b6c450197d3.png" width="470" height="400"/>
  <img src="https://user-images.githubusercontent.com/120545621/217066857-01b48791-cf7d-4762-82d6-433aa1822874.png" width="400" height="200"/>
</p>

