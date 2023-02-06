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
extern "C" void score_matrix(int*, int*, int*, int*, int*, int*, int*, int*, int*);
extern "C" void apatb_score_matrix_hw(volatile void * __xlx_apatb_param_score_m_0, volatile void * __xlx_apatb_param_score_m_1, volatile void * __xlx_apatb_param_score_m_2, volatile void * __xlx_apatb_param_queries_0, volatile void * __xlx_apatb_param_queries_1, volatile void * __xlx_apatb_param_queries_2, volatile void * __xlx_apatb_param_keys_t_0, volatile void * __xlx_apatb_param_keys_t_1, volatile void * __xlx_apatb_param_keys_t_2) {
  // Collect __xlx_score_m_0__tmp_vec
  vector<sc_bv<32> >__xlx_score_m_0__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_score_m_0)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_score_m_0)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_score_m_0)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_score_m_0)[j*4+3];
    __xlx_score_m_0__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_score_m_0 = 3;
  int __xlx_offset_param_score_m_0 = 0;
  int __xlx_offset_byte_param_score_m_0 = 0*4;
  int* __xlx_score_m_0__input_buffer= new int[__xlx_score_m_0__tmp_vec.size()];
  for (int i = 0; i < __xlx_score_m_0__tmp_vec.size(); ++i) {
    __xlx_score_m_0__input_buffer[i] = __xlx_score_m_0__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_score_m_1__tmp_vec
  vector<sc_bv<32> >__xlx_score_m_1__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_score_m_1)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_score_m_1)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_score_m_1)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_score_m_1)[j*4+3];
    __xlx_score_m_1__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_score_m_1 = 3;
  int __xlx_offset_param_score_m_1 = 0;
  int __xlx_offset_byte_param_score_m_1 = 0*4;
  int* __xlx_score_m_1__input_buffer= new int[__xlx_score_m_1__tmp_vec.size()];
  for (int i = 0; i < __xlx_score_m_1__tmp_vec.size(); ++i) {
    __xlx_score_m_1__input_buffer[i] = __xlx_score_m_1__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_score_m_2__tmp_vec
  vector<sc_bv<32> >__xlx_score_m_2__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_score_m_2)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_score_m_2)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_score_m_2)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_score_m_2)[j*4+3];
    __xlx_score_m_2__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_score_m_2 = 3;
  int __xlx_offset_param_score_m_2 = 0;
  int __xlx_offset_byte_param_score_m_2 = 0*4;
  int* __xlx_score_m_2__input_buffer= new int[__xlx_score_m_2__tmp_vec.size()];
  for (int i = 0; i < __xlx_score_m_2__tmp_vec.size(); ++i) {
    __xlx_score_m_2__input_buffer[i] = __xlx_score_m_2__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_queries_0__tmp_vec
  vector<sc_bv<32> >__xlx_queries_0__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_queries_0)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_queries_0)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_queries_0)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_queries_0)[j*4+3];
    __xlx_queries_0__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_queries_0 = 3;
  int __xlx_offset_param_queries_0 = 0;
  int __xlx_offset_byte_param_queries_0 = 0*4;
  int* __xlx_queries_0__input_buffer= new int[__xlx_queries_0__tmp_vec.size()];
  for (int i = 0; i < __xlx_queries_0__tmp_vec.size(); ++i) {
    __xlx_queries_0__input_buffer[i] = __xlx_queries_0__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_queries_1__tmp_vec
  vector<sc_bv<32> >__xlx_queries_1__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_queries_1)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_queries_1)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_queries_1)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_queries_1)[j*4+3];
    __xlx_queries_1__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_queries_1 = 3;
  int __xlx_offset_param_queries_1 = 0;
  int __xlx_offset_byte_param_queries_1 = 0*4;
  int* __xlx_queries_1__input_buffer= new int[__xlx_queries_1__tmp_vec.size()];
  for (int i = 0; i < __xlx_queries_1__tmp_vec.size(); ++i) {
    __xlx_queries_1__input_buffer[i] = __xlx_queries_1__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_queries_2__tmp_vec
  vector<sc_bv<32> >__xlx_queries_2__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_queries_2)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_queries_2)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_queries_2)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_queries_2)[j*4+3];
    __xlx_queries_2__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_queries_2 = 3;
  int __xlx_offset_param_queries_2 = 0;
  int __xlx_offset_byte_param_queries_2 = 0*4;
  int* __xlx_queries_2__input_buffer= new int[__xlx_queries_2__tmp_vec.size()];
  for (int i = 0; i < __xlx_queries_2__tmp_vec.size(); ++i) {
    __xlx_queries_2__input_buffer[i] = __xlx_queries_2__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_keys_t_0__tmp_vec
  vector<sc_bv<32> >__xlx_keys_t_0__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_keys_t_0)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_keys_t_0)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_keys_t_0)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_keys_t_0)[j*4+3];
    __xlx_keys_t_0__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_keys_t_0 = 3;
  int __xlx_offset_param_keys_t_0 = 0;
  int __xlx_offset_byte_param_keys_t_0 = 0*4;
  int* __xlx_keys_t_0__input_buffer= new int[__xlx_keys_t_0__tmp_vec.size()];
  for (int i = 0; i < __xlx_keys_t_0__tmp_vec.size(); ++i) {
    __xlx_keys_t_0__input_buffer[i] = __xlx_keys_t_0__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_keys_t_1__tmp_vec
  vector<sc_bv<32> >__xlx_keys_t_1__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_keys_t_1)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_keys_t_1)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_keys_t_1)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_keys_t_1)[j*4+3];
    __xlx_keys_t_1__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_keys_t_1 = 3;
  int __xlx_offset_param_keys_t_1 = 0;
  int __xlx_offset_byte_param_keys_t_1 = 0*4;
  int* __xlx_keys_t_1__input_buffer= new int[__xlx_keys_t_1__tmp_vec.size()];
  for (int i = 0; i < __xlx_keys_t_1__tmp_vec.size(); ++i) {
    __xlx_keys_t_1__input_buffer[i] = __xlx_keys_t_1__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_keys_t_2__tmp_vec
  vector<sc_bv<32> >__xlx_keys_t_2__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_keys_t_2)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_keys_t_2)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_keys_t_2)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_keys_t_2)[j*4+3];
    __xlx_keys_t_2__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_keys_t_2 = 3;
  int __xlx_offset_param_keys_t_2 = 0;
  int __xlx_offset_byte_param_keys_t_2 = 0*4;
  int* __xlx_keys_t_2__input_buffer= new int[__xlx_keys_t_2__tmp_vec.size()];
  for (int i = 0; i < __xlx_keys_t_2__tmp_vec.size(); ++i) {
    __xlx_keys_t_2__input_buffer[i] = __xlx_keys_t_2__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  score_matrix(__xlx_score_m_0__input_buffer, __xlx_score_m_1__input_buffer, __xlx_score_m_2__input_buffer, __xlx_queries_0__input_buffer, __xlx_queries_1__input_buffer, __xlx_queries_2__input_buffer, __xlx_keys_t_0__input_buffer, __xlx_keys_t_1__input_buffer, __xlx_keys_t_2__input_buffer);
// print __xlx_apatb_param_score_m_0
  sc_bv<32>*__xlx_score_m_0_output_buffer = new sc_bv<32>[__xlx_size_param_score_m_0];
  for (int i = 0; i < __xlx_size_param_score_m_0; ++i) {
    __xlx_score_m_0_output_buffer[i] = __xlx_score_m_0__input_buffer[i+__xlx_offset_param_score_m_0];
  }
  for (int i = 0; i < __xlx_size_param_score_m_0; ++i) {
    ((char*)__xlx_apatb_param_score_m_0)[i*4+0] = __xlx_score_m_0_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_score_m_0)[i*4+1] = __xlx_score_m_0_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_score_m_0)[i*4+2] = __xlx_score_m_0_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_score_m_0)[i*4+3] = __xlx_score_m_0_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_score_m_1
  sc_bv<32>*__xlx_score_m_1_output_buffer = new sc_bv<32>[__xlx_size_param_score_m_1];
  for (int i = 0; i < __xlx_size_param_score_m_1; ++i) {
    __xlx_score_m_1_output_buffer[i] = __xlx_score_m_1__input_buffer[i+__xlx_offset_param_score_m_1];
  }
  for (int i = 0; i < __xlx_size_param_score_m_1; ++i) {
    ((char*)__xlx_apatb_param_score_m_1)[i*4+0] = __xlx_score_m_1_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_score_m_1)[i*4+1] = __xlx_score_m_1_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_score_m_1)[i*4+2] = __xlx_score_m_1_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_score_m_1)[i*4+3] = __xlx_score_m_1_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_score_m_2
  sc_bv<32>*__xlx_score_m_2_output_buffer = new sc_bv<32>[__xlx_size_param_score_m_2];
  for (int i = 0; i < __xlx_size_param_score_m_2; ++i) {
    __xlx_score_m_2_output_buffer[i] = __xlx_score_m_2__input_buffer[i+__xlx_offset_param_score_m_2];
  }
  for (int i = 0; i < __xlx_size_param_score_m_2; ++i) {
    ((char*)__xlx_apatb_param_score_m_2)[i*4+0] = __xlx_score_m_2_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_score_m_2)[i*4+1] = __xlx_score_m_2_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_score_m_2)[i*4+2] = __xlx_score_m_2_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_score_m_2)[i*4+3] = __xlx_score_m_2_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_queries_0
  sc_bv<32>*__xlx_queries_0_output_buffer = new sc_bv<32>[__xlx_size_param_queries_0];
  for (int i = 0; i < __xlx_size_param_queries_0; ++i) {
    __xlx_queries_0_output_buffer[i] = __xlx_queries_0__input_buffer[i+__xlx_offset_param_queries_0];
  }
  for (int i = 0; i < __xlx_size_param_queries_0; ++i) {
    ((char*)__xlx_apatb_param_queries_0)[i*4+0] = __xlx_queries_0_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_queries_0)[i*4+1] = __xlx_queries_0_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_queries_0)[i*4+2] = __xlx_queries_0_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_queries_0)[i*4+3] = __xlx_queries_0_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_queries_1
  sc_bv<32>*__xlx_queries_1_output_buffer = new sc_bv<32>[__xlx_size_param_queries_1];
  for (int i = 0; i < __xlx_size_param_queries_1; ++i) {
    __xlx_queries_1_output_buffer[i] = __xlx_queries_1__input_buffer[i+__xlx_offset_param_queries_1];
  }
  for (int i = 0; i < __xlx_size_param_queries_1; ++i) {
    ((char*)__xlx_apatb_param_queries_1)[i*4+0] = __xlx_queries_1_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_queries_1)[i*4+1] = __xlx_queries_1_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_queries_1)[i*4+2] = __xlx_queries_1_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_queries_1)[i*4+3] = __xlx_queries_1_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_queries_2
  sc_bv<32>*__xlx_queries_2_output_buffer = new sc_bv<32>[__xlx_size_param_queries_2];
  for (int i = 0; i < __xlx_size_param_queries_2; ++i) {
    __xlx_queries_2_output_buffer[i] = __xlx_queries_2__input_buffer[i+__xlx_offset_param_queries_2];
  }
  for (int i = 0; i < __xlx_size_param_queries_2; ++i) {
    ((char*)__xlx_apatb_param_queries_2)[i*4+0] = __xlx_queries_2_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_queries_2)[i*4+1] = __xlx_queries_2_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_queries_2)[i*4+2] = __xlx_queries_2_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_queries_2)[i*4+3] = __xlx_queries_2_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_keys_t_0
  sc_bv<32>*__xlx_keys_t_0_output_buffer = new sc_bv<32>[__xlx_size_param_keys_t_0];
  for (int i = 0; i < __xlx_size_param_keys_t_0; ++i) {
    __xlx_keys_t_0_output_buffer[i] = __xlx_keys_t_0__input_buffer[i+__xlx_offset_param_keys_t_0];
  }
  for (int i = 0; i < __xlx_size_param_keys_t_0; ++i) {
    ((char*)__xlx_apatb_param_keys_t_0)[i*4+0] = __xlx_keys_t_0_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_keys_t_0)[i*4+1] = __xlx_keys_t_0_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_keys_t_0)[i*4+2] = __xlx_keys_t_0_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_keys_t_0)[i*4+3] = __xlx_keys_t_0_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_keys_t_1
  sc_bv<32>*__xlx_keys_t_1_output_buffer = new sc_bv<32>[__xlx_size_param_keys_t_1];
  for (int i = 0; i < __xlx_size_param_keys_t_1; ++i) {
    __xlx_keys_t_1_output_buffer[i] = __xlx_keys_t_1__input_buffer[i+__xlx_offset_param_keys_t_1];
  }
  for (int i = 0; i < __xlx_size_param_keys_t_1; ++i) {
    ((char*)__xlx_apatb_param_keys_t_1)[i*4+0] = __xlx_keys_t_1_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_keys_t_1)[i*4+1] = __xlx_keys_t_1_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_keys_t_1)[i*4+2] = __xlx_keys_t_1_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_keys_t_1)[i*4+3] = __xlx_keys_t_1_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_keys_t_2
  sc_bv<32>*__xlx_keys_t_2_output_buffer = new sc_bv<32>[__xlx_size_param_keys_t_2];
  for (int i = 0; i < __xlx_size_param_keys_t_2; ++i) {
    __xlx_keys_t_2_output_buffer[i] = __xlx_keys_t_2__input_buffer[i+__xlx_offset_param_keys_t_2];
  }
  for (int i = 0; i < __xlx_size_param_keys_t_2; ++i) {
    ((char*)__xlx_apatb_param_keys_t_2)[i*4+0] = __xlx_keys_t_2_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_keys_t_2)[i*4+1] = __xlx_keys_t_2_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_keys_t_2)[i*4+2] = __xlx_keys_t_2_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_keys_t_2)[i*4+3] = __xlx_keys_t_2_output_buffer[i].range(31, 24).to_uint();
  }
}
