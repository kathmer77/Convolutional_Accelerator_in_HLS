#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "transformer.h"

void score_matrix(float score_m[M][O], float queries[M][N], float keys_t[N][O]) {
// Vector Multiplication Q(3x8)*K(8x3) = score matrix(3x3)
#pragma HLS pipeline II = 1
#pragma HLS dependence variable=queries type=inter dependent=false
#pragma HLS dependence variable=keys_t type=inter dependent=false
	LOOP1:for (int m = 0; m < M; m++) {
		#pragma HLS unroll
		LOOP2:for (int o = 0; o < M; o++) {
		   score_m[m][o] = 0;
               #pragma HLS unroll
		      LOOP3:for (int n = 0; n < N; n++) {
			    #pragma HLS unroll
				score_m[m][o] += queries[m][n] * keys_t[n][o];
		      }
		}
	}
}

void softmax_function(float attention_hx[M][O], float score_m_hx_div[M][O], float sum_score_m_hx[M]) {
#pragma HLS pipeline II = 1 // attn_mx cERo
#pragma HLS dependence variable=score_m_hx_div type=inter dependent=false
#pragma HLS dependence variable=sum_score_m_hx type=inter dependent=false
	LOOP4:for (int m = 0; m <M; m++) {
	#pragma HLS unroll
		LOOP5:for (int o = 0; o <O; o++) {
		  #pragma HLS unroll
		  attention_hx[m][o] += exp(score_m_hx_div[m][o]) / sum_score_m_hx[m];
	    }
	}
}

void output_matrix(float output_hx[M][N], float attention_hx[M][O], float values[O][N]) {
// Vector Multiplication Attention(3x3)*V(3x3) = output(3x3)
#pragma HLS pipeline II = 1
#pragma HLS dependence variable=attention_hx type=inter dependent=false
#pragma HLS dependence variable=values type=inter dependent=false
	LOOP6:for (int m = 0; m < M; m++) {
	#pragma HLS unroll
		LOOP7:for (int n = 0; n < N; n++) {
			output_hx[m][n] = 0;
	#pragma HLS unroll
		      LOOP8:for (int o = 0; o < O; o++) {
			    #pragma HLS unroll
		    	  output_hx[m][n] += attention_hx[m][o] * values[o][n];
		      }
		}
	}
}

void output_matrix_linear(float concatenated_output_matrix_linear[M][P], float concatenated_total_output_matrix[M][Q], float matrix_weights_linear1_t[Q][P], float bias_linear[P]) {
// Vector Multiplication Output(3x24)*WT(24x24) = output(3x24)

#pragma HLS pipeline II = 1
#pragma HLS dependence variable=concatenated_total_output_matrix type=inter dependent=false
#pragma HLS dependence variable=matrix_weights_linear1_t type=inter dependent=false
	float output_matrix_l[P][Q] = {};
	LOOP9:for (int m = 0; m < M; m++) {
		#pragma HLS unroll
		LOOP10:for (int p = 0; p < P; p++) {
			   #pragma HLS unroll
		      LOOP11:for (int q = 0; q < Q; q++) {
			         #pragma HLS unroll
		    	  output_matrix_l[m][p] += concatenated_total_output_matrix[m][q] * matrix_weights_linear1_t[q][p];
		      }
		}
	}
// Sum bias (3x24) + (1x24)
#pragma HLS pipeline II = 1
#pragma HLS dependence variable=bias_linear type=inter dependent=false
#pragma HLS dependence variable=output_matrix_l type=inter dependent=false
	LOOP12: for (int m = 0; m<M; m++) {
			#pragma HLS unroll
		LOOP13: for (int p = 0; p<P; p++) {
	        #pragma HLS unroll
			concatenated_output_matrix_linear[m][p] = output_matrix_l[m][p] + bias_linear[p];
		}
	}
}

void output_matrix_linear1_fw(float output_layer1_fw[M][K], float norm_layer1[M][Q], float matrix_weights_linear1_fw_t[Q][K], float bias_linear1_fw[K]) {
	// Vector Multiplication Output(3x24)*WT(24x24) = output(3x24)
	#pragma HLS pipeline II = 1
	   #pragma HLS dependence variable=norm_layer1 type=inter dependent=false
	   #pragma HLS dependence variable=matrix_weights_linear1_fw_t type=inter dependent=false
	float output_matrix_l[P][Q] = {};
	#pragma HLS unroll
		LOOP14:for (int m = 0; m < M; m++) {
			LOOP15:for (int k = 0; k < K; k++) {
	#pragma HLS unroll
			      LOOP11:for (int q = 0; q < Q; q++) {
				    #pragma HLS unroll
			    	  output_matrix_l[m][k] += norm_layer1[m][q] * matrix_weights_linear1_fw_t[q][k];
			      }
			}
		}
	// Sum bias (3x24) + (1x24)
#pragma HLS pipeline II = 1
#pragma HLS dependence variable=bias_linear1_fw type=inter dependent=false
#pragma HLS dependence variable=output_matrix_l type=inter dependent=false
		LOOP16: for (int m = 0; m<M; m++) {
#pragma HLS unroll
			LOOP17: for (int k = 0; k<K; k++) {
		        #pragma HLS unroll

				output_layer1_fw[m][k] = output_matrix_l[m][k] + bias_linear1_fw[k];
			}
		}
}


//void score_matrix(float score_m[M][O], float queries[M][N], float keys_t[N][O]) {
//// Vector Multiplication Q(3x8)*K(8x3) = score matrix(3x3)
//	LOOP1:for (int m = 0; m < M; m++) {
//		LOOP2:for (int o = 0; o < M; o++) {
//		   score_m[m][o] = 0;
//
//		      LOOP3:for (int n = 0; n < N; n++) {
//
//				score_m[m][o] += queries[m][n] * keys_t[n][o];
//		      }
//		}
//	}
//}
//
//void softmax_function(float attention_hx[M][O], float score_m_hx_div[M][O], float sum_score_m_hx[M]) {
//	LOOP4:for (int m = 0; m <M; m++) {
//
//		LOOP5:for (int o = 0; o <O; o++) {
//		  attention_hx[m][o] += exp(score_m_hx_div[m][o]) / sum_score_m_hx[m];
//	    }
//	}
//}
//
//void output_matrix(float output_hx[M][N], float attention_hx[M][O], float values[O][N]) {
//// Vector Multiplication Attention(3x3)*V(3x3) = output(3x3)
//	LOOP6:for (int m = 0; m < M; m++) {
//		LOOP7:for (int n = 0; n < N; n++) {
//			output_hx[m][n] = 0;
//
//		      LOOP8:for (int o = 0; o < O; o++) {
//
//		    	  output_hx[m][n] += attention_hx[m][o] * values[o][n];
//		      }
//		}
//	}
//}
//
//
//void output_matrix_linear(float concatenated_output_matrix_linear[M][P], float concatenated_total_output_matrix[M][Q], float matrix_weights_linear1_t[Q][P], float bias_linear[P]) {
//// Vector Multiplication Output(3x24)*WT(24x24) = output(3x24)
//	float output_matrix_l[P][Q] = {};
//	LOOP9:for (int m = 0; m < M; m++) {
//		LOOP10:for (int p = 0; p < P; p++) {
//
//		      LOOP11:for (int q = 0; q < Q; q++) {
//
//		    	  output_matrix_l[m][p] += concatenated_total_output_matrix[m][q] * matrix_weights_linear1_t[q][p];
//		      }
//		}
//	}
//// Sum bias (3x24) + (1x24)
//	LOOP12: for (int m = 0; m<M; m++) {
//
//		LOOP13: for (int p = 0; p<P; p++) {
//
//			concatenated_output_matrix_linear[m][p] = output_matrix_l[m][p] + bias_linear[p];
//		}
//	}
//}
//
//void output_matrix_linear1_fw(float output_layer1_fw[M][K], float norm_layer1[M][Q], float matrix_weights_linear1_fw_t[Q][K], float bias_linear1_fw[K]) {
//	// Vector Multiplication Output(3x24)*WT(24x24) = output(3x24)
//		float output_matrix_l[P][Q] = {};
//		LOOP14:for (int m = 0; m < M; m++) {
//			LOOP15:for (int k = 0; k < K; k++) {
//
//			      LOOP11:for (int q = 0; q < Q; q++) {
//
//			    	  output_matrix_l[m][k] += norm_layer1[m][q] * matrix_weights_linear1_fw_t[q][k];
//			      }
//			}
//		}
//	// Sum bias (3x24) + (1x24)
//		LOOP16: for (int m = 0; m<M; m++) {
//
//			LOOP17: for (int k = 0; k<K; k++) {
//
//				output_layer1_fw[m][k] = output_matrix_l[m][k] + bias_linear1_fw[k];
//			}
//		}
//}


//// First Code
//void score_matrix(float score_m[M][O], float queries[M][N], float keys_t[N][O]) {
//// Vector Multiplication Q(3x8)*K(8x3) = score matrix(3x3)
//	LOOP1:for (int m = 0; m < M; m++) {
//		LOOP2:for (int o = 0; o < M; o++) {
//		   score_m[m][o] = 0;
//		   #pragma HLS pipeline II = 1
//		   #pragma HLS dependence variable=queries type=inter dependent=false
//		   #pragma HLS dependence variable=keys_t type=inter dependent=false
//		      LOOP3:for (int n = 0; n < N; n++) {
//			    #pragma HLS unroll
//				score_m[m][o] += queries[m][n] * keys_t[n][o];
//		      }
//		}
//	}
//}
//
//void softmax_function(float attention_hx[M][O], float score_m_hx_div[M][O], float sum_score_m_hx[M]) {
//	LOOP4:for (int m = 0; m <M; m++) {
//	#pragma HLS pipeline II = 1 // attn_mx cERo
//	#pragma HLS dependence variable=score_m_hx_div type=inter dependent=false
//	#pragma HLS dependence variable=sum_score_m_hx type=inter dependent=false
//		LOOP5:for (int o = 0; o <O; o++) {
//		  #pragma HLS unroll
//		  attention_hx[m][o] += exp(score_m_hx_div[m][o]) / sum_score_m_hx[m];
//	    }
//	}
//}
//
//void output_matrix(float output_hx[M][N], float attention_hx[M][O], float values[O][N]) {
//// Vector Multiplication Attention(3x3)*V(3x3) = output(3x3)
//	LOOP6:for (int m = 0; m < M; m++) {
//		LOOP7:for (int n = 0; n < N; n++) {
//			output_hx[m][n] = 0;
//		   #pragma HLS pipeline II = 1
//		   #pragma HLS dependence variable=attention_hx type=inter dependent=false
//		   #pragma HLS dependence variable=values type=inter dependent=false
//		      LOOP8:for (int o = 0; o < O; o++) {
//			    #pragma HLS unroll
//		    	  output_hx[m][n] += attention_hx[m][o] * values[o][n];
//		      }
//		}
//	}
//}
//
//
//void output_matrix_linear(float concatenated_output_matrix_linear[M][P], float concatenated_total_output_matrix[M][Q], float matrix_weights_linear1_t[Q][P], float bias_linear[P]) {
//// Vector Multiplication Output(3x24)*WT(24x24) = output(3x24)
//	float output_matrix_l[P][Q] = {};
//	LOOP9:for (int m = 0; m < M; m++) {
//		LOOP10:for (int p = 0; p < P; p++) {
//		   #pragma HLS pipeline II = 1
//		   #pragma HLS dependence variable=concatenated_total_output_matrix type=inter dependent=false
//		   #pragma HLS dependence variable=matrix_weights_linear1_t type=inter dependent=false
//		      LOOP11:for (int q = 0; q < Q; q++) {
//			    #pragma HLS unroll
//		    	  output_matrix_l[m][p] += concatenated_total_output_matrix[m][q] * matrix_weights_linear1_t[q][p];
//		      }
//		}
//	}
//// Sum bias (3x24) + (1x24)
//	LOOP12: for (int m = 0; m<M; m++) {
//	    #pragma HLS pipeline II = 1
//        #pragma HLS dependence variable=bias_linear type=inter dependent=false
//		#pragma HLS dependence variable=output_matrix_l type=inter dependent=false
//		LOOP13: for (int p = 0; p<P; p++) {
//	        #pragma HLS unroll
//			concatenated_output_matrix_linear[m][p] = output_matrix_l[m][p] + bias_linear[p];
//		}
//	}
//}
//
//void output_matrix_linear1_fw(float output_layer1_fw[M][K], float norm_layer1[M][Q], float matrix_weights_linear1_fw_t[Q][K], float bias_linear1_fw[K]) {
//	// Vector Multiplication Output(3x24)*WT(24x24) = output(3x24)
//		float output_matrix_l[P][Q] = {};
//		LOOP14:for (int m = 0; m < M; m++) {
//			LOOP15:for (int k = 0; k < K; k++) {
//			   #pragma HLS pipeline II = 1
//			   #pragma HLS dependence variable=norm_layer1 type=inter dependent=false
//			   #pragma HLS dependence variable=matrix_weights_linear1_fw_t type=inter dependent=false
//			      LOOP11:for (int q = 0; q < Q; q++) {
//				    #pragma HLS unroll
//			    	  output_matrix_l[m][k] += norm_layer1[m][q] * matrix_weights_linear1_fw_t[q][k];
//			      }
//			}
//		}
//	// Sum bias (3x24) + (1x24)
//		LOOP16: for (int m = 0; m<M; m++) {
//		    #pragma HLS pipeline II = 1
//			LOOP17: for (int k = 0; k<K; k++) {
//		        #pragma HLS unroll
//	#pragma HLS dependence variable=bias_linear1_fw type=inter dependent=false
//	#pragma HLS dependence variable=output_matrix_l type=inter dependent=false
//				output_layer1_fw[m][k] = output_matrix_l[m][k] + bias_linear1_fw[k];
//			}
//		}
//}



