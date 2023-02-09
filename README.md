# Convolutional_Accelerator_in_HLS

<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066015-105a76cd-94fe-4b1f-b5b0-9ea4993c2139.png" width="800" height="250"/>
</p>


The Transformer model is a neural network that aims to solve sequence-to-sequence tasks, such as natural language tests, genome sequences and sound signals among other data. 
Mostly used for Natural Language Processing (NLP) and Computer Vision (CV) applications. Proposed in "[Attention is All You Need](https://arxiv.org/abs/1706.03762)” by Google in 2017.

The overall architecture of the Transformer involves an encoder block on the left, and a decoder block on the right. 
Both encoder and decoder consist of Multi-Head Attention and Feed Forward layers. These blocks can be stacked on top of each other multiple times, 
which is indicated by Nx. In broad terms, The Transformer takes an input sentence in the form of a sequence of vectors and translate these into an “encoding vector”, 
which is decoded back into another different sequence.

<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066554-12898cb9-d77e-43ef-80e6-6e3c0a824c5a.png" width="300" height="350"/>
</p>

## Project Description

This project aims to create an HLS implementation of the important layers of the Transformer architecture and explore the effects of optimization on FPGA resources utilization and latency. The effort is focused on implementing the scaled-dot-product and multi-head attention layers, along with linear layers that form the building block of many sub-layers throughout the architecture. 

For verification purposes, it has been used a “from-scratch” implementation of the model instead of one using high level built-in classes,
so that,  I could examine and build individual layers in HLS using the functionality described in the Pytorch as a guide. 
To verify the correct performance of the constructed layers, the golden data from the model was used to run the code. 
A check function is implemented to compare the output of each layer with the data from the model by calculating the average error. This error is negligible with respect to the values of the golden data.


### Attention Mechanism

The heart of the Transformer is the incorporation of the Attention Mechanism. Attention is a means of selectively weighting different elements in the input data, so that they will have an impact on the remaining layers. In other words, this mechanism indicates in which parts of the input vector the network should focus on in order to generate the output vector. 
For instance, in translation, the word “it” can be translated into Spanish or French using the correct gender because the attention mechanism put the spotlight in all the relevant words in the original sentence.

<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066664-8c21ad8c-6d62-4c6b-8329-44dded4fa5e7.png" width="370" height="300"/>
</p>

### Computation 

Considering the translation example for better understanding: the implementation of the Attention Mechanism consists of converting the input data into “Key, Query and Value" vectors. 

Q is the matrix that contains the Query, vector representation of one word in the sequence. 
K corresponds to the Key vector representing all the words in the sequence. 
Finally, V is the matrix of the values, which is also, another vector representation of the entirely sequence. 

The dot product of the Key and Query vectors provide the attention weight. This is how much focus should a word be put with respect to other words.
For this project, I have defined this as the “Score Matrix”. Once the matrix is obtained, it is squashed using a “Softmax” function so that all attention weights will have a total weighting of 1. Lastly, the Value vector is multiplied by this result, before being fed into subsequent layers. Remaining necessary layers have been built according to the architecture.


<p align="center">
  <img src="https://user-images.githubusercontent.com/120545621/217066783-ce57483a-026d-4d00-b2a5-1b6c450197d3.png" width="470" height="400"/>
  <img src="https://user-images.githubusercontent.com/120545621/217066857-01b48791-cf7d-4762-82d6-433aa1822874.png" width="400" height="200"/>
</p>

### Optimization

For convenience, size changes have been incurred throughout the Transformer model. For instance, the input sequence length has been changed from 512 to 24  parameters in order to redure the number of these in consecutive layers. So that, the HLS design is small enough to easily fit into a lower end FPGA and nearly fully unroll all but the topmost layers and still not reach the number of DPS available in the targeted FPGA. The outermost loops have been pipelined. Since the concern of the Transformer architecture in this project is the Inference to obtain the golden data, an untrained model and arbitrary weights has been used. This would change the parameters and golden results every time the model is running however it does not change the functionality. An example of these reshaped values can be found in "[output_inference.txt](https://github.com/katmer7/Convolutional_Accelerator_in_HLS/blob/main/Python%20Transformer%20Neural%20Network/output_inference.txt)"

Optimization Mechanisms evaluated:
- To improve matrix performance, Array Partition has been implemented in Query, Value and Key matrices
- Pipeline and Dependence Pragmas
- Pipeline, Dependence and Unrolling Pragmas

FPGAs resources evaluated:
- DPS
- FFs
- LUTs

NOTE: Optimization choices depend on both neural network model and hardware preference. This project results aim to compare the impact of the different optimizations according to design constraints. For additional information about optimization mechanisms can be found in Xilinx documentation portal. Vitis HLS allows adding directives manually or by sotfware configuration.

## Setup
This project is executed in Vitis HLS version 2021.1

## References

* Vitis Download: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis/2021-1.html

* Vitis Introduction and Getting Started: https://xilinx.github.io/Vitis-Tutorials/2021-1/build/html/docs/Getting_Started/Vitis/Getting_Started_Vitis.html

* Xilinx Documentation - Pragmas in HLS: https://docs.xilinx.com/r/en-US/ug1399-vitis-hls/HLS-Pragmas

* Xilinx Documentation - Array Partition: https://xilinx.github.io/Vitis_Accel_Examples/2020.2/html/array_partition.html

* Transformer Neural Network: https://ai.googleblog.com/2017/08/transformer-novel-neural-network.html 
