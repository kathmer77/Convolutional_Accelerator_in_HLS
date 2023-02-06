############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project TRT
set_top score_matrix
add_files transformer.h
add_files transformer.cpp
add_files -tb tb_transformer.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "Opt2" -flow_target vivado
set_part {xcvu11p-flga2577-1-e}
create_clock -period 10 -name default
source "./TRT/Opt2/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
