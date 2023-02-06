############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_top -name score_matrix "score_matrix"
set_directive_array_partition -type complete -dim 1 "score_matrix" score_m
set_directive_array_partition -type complete -dim 1 "score_matrix" queries
set_directive_array_partition -type complete -dim 1 "score_matrix" keys_t
