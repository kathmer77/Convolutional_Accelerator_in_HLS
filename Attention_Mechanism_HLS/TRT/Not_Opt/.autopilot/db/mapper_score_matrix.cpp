#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
extern "C" void score_matrix(int*, int*, int*);
extern "C" void apatb_score_matrix_hw(volatile void * __xlx_apatb_param_score_m, volatile void * __xlx_apatb_param_queries, volatile void * __xlx_apatb_param_keys_t) {
  // Collect __xlx_score_m__tmp_vec
  vector<sc_bv<32> >__xlx_score_m__tmp_vec;
  for (int j = 0, e = 9; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_score_m)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_score_m)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_score_m)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_score_m)[j*4+3];
    __xlx_score_m__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_score_m = 9;
  int __xlx_offset_param_score_m = 0;
  int __xlx_offset_byte_param_score_m = 0*4;
  int* __xlx_score_m__input_buffer= new int[__xlx_score_m__tmp_vec.size()];
  for (int i = 0; i < __xlx_score_m__tmp_vec.size(); ++i) {
    __xlx_score_m__input_buffer[i] = __xlx_score_m__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_queries__tmp_vec
  vector<sc_bv<32> >__xlx_queries__tmp_vec;
  for (int j = 0, e = 9; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_queries)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_queries)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_queries)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_queries)[j*4+3];
    __xlx_queries__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_queries = 9;
  int __xlx_offset_param_queries = 0;
  int __xlx_offset_byte_param_queries = 0*4;
  int* __xlx_queries__input_buffer= new int[__xlx_queries__tmp_vec.size()];
  for (int i = 0; i < __xlx_queries__tmp_vec.size(); ++i) {
    __xlx_queries__input_buffer[i] = __xlx_queries__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_keys_t__tmp_vec
  vector<sc_bv<32> >__xlx_keys_t__tmp_vec;
  for (int j = 0, e = 9; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_keys_t)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_keys_t)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_keys_t)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_keys_t)[j*4+3];
    __xlx_keys_t__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_keys_t = 9;
  int __xlx_offset_param_keys_t = 0;
  int __xlx_offset_byte_param_keys_t = 0*4;
  int* __xlx_keys_t__input_buffer= new int[__xlx_keys_t__tmp_vec.size()];
  for (int i = 0; i < __xlx_keys_t__tmp_vec.size(); ++i) {
    __xlx_keys_t__input_buffer[i] = __xlx_keys_t__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  score_matrix(__xlx_score_m__input_buffer, __xlx_queries__input_buffer, __xlx_keys_t__input_buffer);
// print __xlx_apatb_param_score_m
  sc_bv<32>*__xlx_score_m_output_buffer = new sc_bv<32>[__xlx_size_param_score_m];
  for (int i = 0; i < __xlx_size_param_score_m; ++i) {
    __xlx_score_m_output_buffer[i] = __xlx_score_m__input_buffer[i+__xlx_offset_param_score_m];
  }
  for (int i = 0; i < __xlx_size_param_score_m; ++i) {
    ((char*)__xlx_apatb_param_score_m)[i*4+0] = __xlx_score_m_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_score_m)[i*4+1] = __xlx_score_m_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_score_m)[i*4+2] = __xlx_score_m_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_score_m)[i*4+3] = __xlx_score_m_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_queries
  sc_bv<32>*__xlx_queries_output_buffer = new sc_bv<32>[__xlx_size_param_queries];
  for (int i = 0; i < __xlx_size_param_queries; ++i) {
    __xlx_queries_output_buffer[i] = __xlx_queries__input_buffer[i+__xlx_offset_param_queries];
  }
  for (int i = 0; i < __xlx_size_param_queries; ++i) {
    ((char*)__xlx_apatb_param_queries)[i*4+0] = __xlx_queries_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_queries)[i*4+1] = __xlx_queries_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_queries)[i*4+2] = __xlx_queries_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_queries)[i*4+3] = __xlx_queries_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_keys_t
  sc_bv<32>*__xlx_keys_t_output_buffer = new sc_bv<32>[__xlx_size_param_keys_t];
  for (int i = 0; i < __xlx_size_param_keys_t; ++i) {
    __xlx_keys_t_output_buffer[i] = __xlx_keys_t__input_buffer[i+__xlx_offset_param_keys_t];
  }
  for (int i = 0; i < __xlx_size_param_keys_t; ++i) {
    ((char*)__xlx_apatb_param_keys_t)[i*4+0] = __xlx_keys_t_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_keys_t)[i*4+1] = __xlx_keys_t_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_keys_t)[i*4+2] = __xlx_keys_t_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_keys_t)[i*4+3] = __xlx_keys_t_output_buffer[i].range(31, 24).to_uint();
  }
}
