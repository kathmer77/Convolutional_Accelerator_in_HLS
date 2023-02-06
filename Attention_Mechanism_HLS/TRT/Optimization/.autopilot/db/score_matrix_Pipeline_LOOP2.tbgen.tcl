set moduleName score_matrix_Pipeline_LOOP2
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {score_matrix_Pipeline_LOOP2}
set C_modelType { void 0 }
set C_modelArgList {
	{ score_m_0 int 32 regular {array 3 { 0 3 } 0 1 }  }
	{ keys_t_0 int 32 regular {array 3 { 1 3 } 1 1 }  }
	{ empty_4 float 32 regular  }
	{ keys_t_1 int 32 regular {array 3 { 1 3 } 1 1 }  }
	{ empty_5 float 32 regular  }
	{ keys_t_2 int 32 regular {array 3 { 1 3 } 1 1 }  }
	{ empty float 32 regular  }
	{ m int 2 regular  }
	{ score_m_1 int 32 regular {array 3 { 0 3 } 0 1 }  }
	{ score_m_2 int 32 regular {array 3 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "score_m_0", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "keys_t_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_4", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "keys_t_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty_5", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "keys_t_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "empty", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "m", "interface" : "wire", "bitwidth" : 2, "direction" : "READONLY"} , 
 	{ "Name" : "score_m_1", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "score_m_2", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 31
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ score_m_0_address0 sc_out sc_lv 2 signal 0 } 
	{ score_m_0_ce0 sc_out sc_logic 1 signal 0 } 
	{ score_m_0_we0 sc_out sc_logic 1 signal 0 } 
	{ score_m_0_d0 sc_out sc_lv 32 signal 0 } 
	{ keys_t_0_address0 sc_out sc_lv 2 signal 1 } 
	{ keys_t_0_ce0 sc_out sc_logic 1 signal 1 } 
	{ keys_t_0_q0 sc_in sc_lv 32 signal 1 } 
	{ empty_4 sc_in sc_lv 32 signal 2 } 
	{ keys_t_1_address0 sc_out sc_lv 2 signal 3 } 
	{ keys_t_1_ce0 sc_out sc_logic 1 signal 3 } 
	{ keys_t_1_q0 sc_in sc_lv 32 signal 3 } 
	{ empty_5 sc_in sc_lv 32 signal 4 } 
	{ keys_t_2_address0 sc_out sc_lv 2 signal 5 } 
	{ keys_t_2_ce0 sc_out sc_logic 1 signal 5 } 
	{ keys_t_2_q0 sc_in sc_lv 32 signal 5 } 
	{ empty sc_in sc_lv 32 signal 6 } 
	{ m sc_in sc_lv 2 signal 7 } 
	{ score_m_1_address0 sc_out sc_lv 2 signal 8 } 
	{ score_m_1_ce0 sc_out sc_logic 1 signal 8 } 
	{ score_m_1_we0 sc_out sc_logic 1 signal 8 } 
	{ score_m_1_d0 sc_out sc_lv 32 signal 8 } 
	{ score_m_2_address0 sc_out sc_lv 2 signal 9 } 
	{ score_m_2_ce0 sc_out sc_logic 1 signal 9 } 
	{ score_m_2_we0 sc_out sc_logic 1 signal 9 } 
	{ score_m_2_d0 sc_out sc_lv 32 signal 9 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "score_m_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "score_m_0", "role": "address0" }} , 
 	{ "name": "score_m_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m_0", "role": "ce0" }} , 
 	{ "name": "score_m_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m_0", "role": "we0" }} , 
 	{ "name": "score_m_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "score_m_0", "role": "d0" }} , 
 	{ "name": "keys_t_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "keys_t_0", "role": "address0" }} , 
 	{ "name": "keys_t_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "keys_t_0", "role": "ce0" }} , 
 	{ "name": "keys_t_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "keys_t_0", "role": "q0" }} , 
 	{ "name": "empty_4", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_4", "role": "default" }} , 
 	{ "name": "keys_t_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "keys_t_1", "role": "address0" }} , 
 	{ "name": "keys_t_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "keys_t_1", "role": "ce0" }} , 
 	{ "name": "keys_t_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "keys_t_1", "role": "q0" }} , 
 	{ "name": "empty_5", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty_5", "role": "default" }} , 
 	{ "name": "keys_t_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "keys_t_2", "role": "address0" }} , 
 	{ "name": "keys_t_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "keys_t_2", "role": "ce0" }} , 
 	{ "name": "keys_t_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "keys_t_2", "role": "q0" }} , 
 	{ "name": "empty", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "empty", "role": "default" }} , 
 	{ "name": "m", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "m", "role": "default" }} , 
 	{ "name": "score_m_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "score_m_1", "role": "address0" }} , 
 	{ "name": "score_m_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m_1", "role": "ce0" }} , 
 	{ "name": "score_m_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m_1", "role": "we0" }} , 
 	{ "name": "score_m_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "score_m_1", "role": "d0" }} , 
 	{ "name": "score_m_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "score_m_2", "role": "address0" }} , 
 	{ "name": "score_m_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m_2", "role": "ce0" }} , 
 	{ "name": "score_m_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m_2", "role": "we0" }} , 
 	{ "name": "score_m_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "score_m_2", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7"],
		"CDFG" : "score_matrix_Pipeline_LOOP2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "16", "EstimateLatencyMax" : "16",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "score_m_0", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "keys_t_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "empty_4", "Type" : "None", "Direction" : "I"},
			{"Name" : "keys_t_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "empty_5", "Type" : "None", "Direction" : "I"},
			{"Name" : "keys_t_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "empty", "Type" : "None", "Direction" : "I"},
			{"Name" : "m", "Type" : "None", "Direction" : "I"},
			{"Name" : "score_m_1", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "score_m_2", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "LOOP2", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter12", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter12", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_3_full_dsp_1_U1", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_3_full_dsp_1_U2", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_3_full_dsp_1_U3", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U4", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U5", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U6", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	score_matrix_Pipeline_LOOP2 {
		score_m_0 {Type O LastRead -1 FirstWrite 12}
		keys_t_0 {Type I LastRead 0 FirstWrite -1}
		empty_4 {Type I LastRead 0 FirstWrite -1}
		keys_t_1 {Type I LastRead 3 FirstWrite -1}
		empty_5 {Type I LastRead 0 FirstWrite -1}
		keys_t_2 {Type I LastRead 6 FirstWrite -1}
		empty {Type I LastRead 0 FirstWrite -1}
		m {Type I LastRead 0 FirstWrite -1}
		score_m_1 {Type O LastRead -1 FirstWrite 12}
		score_m_2 {Type O LastRead -1 FirstWrite 12}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "16", "Max" : "16"}
	, {"Name" : "Interval", "Min" : "16", "Max" : "16"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	score_m_0 { ap_memory {  { score_m_0_address0 mem_address 1 2 }  { score_m_0_ce0 mem_ce 1 1 }  { score_m_0_we0 mem_we 1 1 }  { score_m_0_d0 mem_din 1 32 } } }
	keys_t_0 { ap_memory {  { keys_t_0_address0 mem_address 1 2 }  { keys_t_0_ce0 mem_ce 1 1 }  { keys_t_0_q0 mem_dout 0 32 } } }
	empty_4 { ap_none {  { empty_4 in_data 0 32 } } }
	keys_t_1 { ap_memory {  { keys_t_1_address0 mem_address 1 2 }  { keys_t_1_ce0 mem_ce 1 1 }  { keys_t_1_q0 mem_dout 0 32 } } }
	empty_5 { ap_none {  { empty_5 in_data 0 32 } } }
	keys_t_2 { ap_memory {  { keys_t_2_address0 mem_address 1 2 }  { keys_t_2_ce0 mem_ce 1 1 }  { keys_t_2_q0 mem_dout 0 32 } } }
	empty { ap_none {  { empty in_data 0 32 } } }
	m { ap_none {  { m in_data 0 2 } } }
	score_m_1 { ap_memory {  { score_m_1_address0 mem_address 1 2 }  { score_m_1_ce0 mem_ce 1 1 }  { score_m_1_we0 mem_we 1 1 }  { score_m_1_d0 mem_din 1 32 } } }
	score_m_2 { ap_memory {  { score_m_2_address0 mem_address 1 2 }  { score_m_2_ce0 mem_ce 1 1 }  { score_m_2_we0 mem_we 1 1 }  { score_m_2_d0 mem_din 1 32 } } }
}
