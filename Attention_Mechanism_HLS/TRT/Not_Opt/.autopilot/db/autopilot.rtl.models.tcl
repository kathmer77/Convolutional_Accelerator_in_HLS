set SynModuleInfo {
  {SRCNAME score_matrix MODELNAME score_matrix RTLNAME score_matrix IS_TOP 1
    SUBMODULES {
      {MODELNAME score_matrix_fadd_32ns_32ns_32_3_full_dsp_1 RTLNAME score_matrix_fadd_32ns_32ns_32_3_full_dsp_1 BINDTYPE op TYPE fadd IMPL fulldsp LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME score_matrix_fmul_32ns_32ns_32_2_max_dsp_1 RTLNAME score_matrix_fmul_32ns_32ns_32_2_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME score_matrix_flow_control_loop_pipe RTLNAME score_matrix_flow_control_loop_pipe BINDTYPE interface TYPE internal_upc_flow_control INSTNAME score_matrix_flow_control_loop_pipe_U}
    }
  }
}
