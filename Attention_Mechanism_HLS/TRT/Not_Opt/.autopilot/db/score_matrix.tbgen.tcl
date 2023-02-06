set moduleName score_matrix
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {score_matrix}
set C_modelType { void 0 }
set C_modelArgList {
	{ score_m int 32 regular {array 9 { 0 3 } 0 1 }  }
	{ queries int 32 regular {array 9 { 1 1 } 1 1 }  }
	{ keys_t int 32 regular {array 9 { 1 1 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "score_m", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "queries", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "keys_t", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ score_m_address0 sc_out sc_lv 4 signal 0 } 
	{ score_m_ce0 sc_out sc_logic 1 signal 0 } 
	{ score_m_we0 sc_out sc_logic 1 signal 0 } 
	{ score_m_d0 sc_out sc_lv 32 signal 0 } 
	{ queries_address0 sc_out sc_lv 4 signal 1 } 
	{ queries_ce0 sc_out sc_logic 1 signal 1 } 
	{ queries_q0 sc_in sc_lv 32 signal 1 } 
	{ queries_address1 sc_out sc_lv 4 signal 1 } 
	{ queries_ce1 sc_out sc_logic 1 signal 1 } 
	{ queries_q1 sc_in sc_lv 32 signal 1 } 
	{ keys_t_address0 sc_out sc_lv 4 signal 2 } 
	{ keys_t_ce0 sc_out sc_logic 1 signal 2 } 
	{ keys_t_q0 sc_in sc_lv 32 signal 2 } 
	{ keys_t_address1 sc_out sc_lv 4 signal 2 } 
	{ keys_t_ce1 sc_out sc_logic 1 signal 2 } 
	{ keys_t_q1 sc_in sc_lv 32 signal 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "score_m_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "score_m", "role": "address0" }} , 
 	{ "name": "score_m_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m", "role": "ce0" }} , 
 	{ "name": "score_m_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "score_m", "role": "we0" }} , 
 	{ "name": "score_m_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "score_m", "role": "d0" }} , 
 	{ "name": "queries_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "queries", "role": "address0" }} , 
 	{ "name": "queries_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "queries", "role": "ce0" }} , 
 	{ "name": "queries_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "queries", "role": "q0" }} , 
 	{ "name": "queries_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "queries", "role": "address1" }} , 
 	{ "name": "queries_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "queries", "role": "ce1" }} , 
 	{ "name": "queries_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "queries", "role": "q1" }} , 
 	{ "name": "keys_t_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "keys_t", "role": "address0" }} , 
 	{ "name": "keys_t_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "keys_t", "role": "ce0" }} , 
 	{ "name": "keys_t_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "keys_t", "role": "q0" }} , 
 	{ "name": "keys_t_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "keys_t", "role": "address1" }} , 
 	{ "name": "keys_t_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "keys_t", "role": "ce1" }} , 
 	{ "name": "keys_t_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "keys_t", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5"],
		"CDFG" : "score_matrix",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "30", "EstimateLatencyMax" : "30",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "score_m", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "queries", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "keys_t", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "LOOP1_LOOP2", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "2", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter6", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter6", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_3_full_dsp_1_U1", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_3_full_dsp_1_U2", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U3", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_2_max_dsp_1_U4", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	score_matrix {
		score_m {Type O LastRead -1 FirstWrite 12}
		queries {Type I LastRead 2 FirstWrite -1}
		keys_t {Type I LastRead 2 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "30", "Max" : "30"}
	, {"Name" : "Interval", "Min" : "31", "Max" : "31"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	score_m { ap_memory {  { score_m_address0 mem_address 1 4 }  { score_m_ce0 mem_ce 1 1 }  { score_m_we0 mem_we 1 1 }  { score_m_d0 mem_din 1 32 } } }
	queries { ap_memory {  { queries_address0 mem_address 1 4 }  { queries_ce0 mem_ce 1 1 }  { queries_q0 mem_dout 0 32 }  { queries_address1 MemPortADDR2 1 4 }  { queries_ce1 MemPortCE2 1 1 }  { queries_q1 MemPortDOUT2 0 32 } } }
	keys_t { ap_memory {  { keys_t_address0 mem_address 1 4 }  { keys_t_ce0 mem_ce 1 1 }  { keys_t_q0 mem_dout 0 32 }  { keys_t_address1 MemPortADDR2 1 4 }  { keys_t_ce1 MemPortCE2 1 1 }  { keys_t_q1 MemPortDOUT2 0 32 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
