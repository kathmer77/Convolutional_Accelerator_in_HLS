#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_score_m_0 "../tv/cdatafile/c.score_matrix.autotvin_score_m_0.dat"
#define AUTOTB_TVOUT_score_m_0 "../tv/cdatafile/c.score_matrix.autotvout_score_m_0.dat"
// wrapc file define:
#define AUTOTB_TVIN_score_m_1 "../tv/cdatafile/c.score_matrix.autotvin_score_m_1.dat"
#define AUTOTB_TVOUT_score_m_1 "../tv/cdatafile/c.score_matrix.autotvout_score_m_1.dat"
// wrapc file define:
#define AUTOTB_TVIN_score_m_2 "../tv/cdatafile/c.score_matrix.autotvin_score_m_2.dat"
#define AUTOTB_TVOUT_score_m_2 "../tv/cdatafile/c.score_matrix.autotvout_score_m_2.dat"
// wrapc file define:
#define AUTOTB_TVIN_queries_0 "../tv/cdatafile/c.score_matrix.autotvin_queries_0.dat"
#define AUTOTB_TVOUT_queries_0 "../tv/cdatafile/c.score_matrix.autotvout_queries_0.dat"
// wrapc file define:
#define AUTOTB_TVIN_queries_1 "../tv/cdatafile/c.score_matrix.autotvin_queries_1.dat"
#define AUTOTB_TVOUT_queries_1 "../tv/cdatafile/c.score_matrix.autotvout_queries_1.dat"
// wrapc file define:
#define AUTOTB_TVIN_queries_2 "../tv/cdatafile/c.score_matrix.autotvin_queries_2.dat"
#define AUTOTB_TVOUT_queries_2 "../tv/cdatafile/c.score_matrix.autotvout_queries_2.dat"
// wrapc file define:
#define AUTOTB_TVIN_keys_t_0 "../tv/cdatafile/c.score_matrix.autotvin_keys_t_0.dat"
#define AUTOTB_TVOUT_keys_t_0 "../tv/cdatafile/c.score_matrix.autotvout_keys_t_0.dat"
// wrapc file define:
#define AUTOTB_TVIN_keys_t_1 "../tv/cdatafile/c.score_matrix.autotvin_keys_t_1.dat"
#define AUTOTB_TVOUT_keys_t_1 "../tv/cdatafile/c.score_matrix.autotvout_keys_t_1.dat"
// wrapc file define:
#define AUTOTB_TVIN_keys_t_2 "../tv/cdatafile/c.score_matrix.autotvin_keys_t_2.dat"
#define AUTOTB_TVOUT_keys_t_2 "../tv/cdatafile/c.score_matrix.autotvout_keys_t_2.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_score_m_0 "../tv/rtldatafile/rtl.score_matrix.autotvout_score_m_0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_score_m_1 "../tv/rtldatafile/rtl.score_matrix.autotvout_score_m_1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_score_m_2 "../tv/rtldatafile/rtl.score_matrix.autotvout_score_m_2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_queries_0 "../tv/rtldatafile/rtl.score_matrix.autotvout_queries_0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_queries_1 "../tv/rtldatafile/rtl.score_matrix.autotvout_queries_1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_queries_2 "../tv/rtldatafile/rtl.score_matrix.autotvout_queries_2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_keys_t_0 "../tv/rtldatafile/rtl.score_matrix.autotvout_keys_t_0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_keys_t_1 "../tv/rtldatafile/rtl.score_matrix.autotvout_keys_t_1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_keys_t_2 "../tv/rtldatafile/rtl.score_matrix.autotvout_keys_t_2.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  score_m_0_depth = 0;
  score_m_1_depth = 0;
  score_m_2_depth = 0;
  queries_0_depth = 0;
  queries_1_depth = 0;
  queries_2_depth = 0;
  keys_t_0_depth = 0;
  keys_t_1_depth = 0;
  keys_t_2_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{score_m_0 " << score_m_0_depth << "}\n";
  total_list << "{score_m_1 " << score_m_1_depth << "}\n";
  total_list << "{score_m_2 " << score_m_2_depth << "}\n";
  total_list << "{queries_0 " << queries_0_depth << "}\n";
  total_list << "{queries_1 " << queries_1_depth << "}\n";
  total_list << "{queries_2 " << queries_2_depth << "}\n";
  total_list << "{keys_t_0 " << keys_t_0_depth << "}\n";
  total_list << "{keys_t_1 " << keys_t_1_depth << "}\n";
  total_list << "{keys_t_2 " << keys_t_2_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int score_m_0_depth;
    int score_m_1_depth;
    int score_m_2_depth;
    int queries_0_depth;
    int queries_1_depth;
    int queries_2_depth;
    int keys_t_0_depth;
    int keys_t_1_depth;
    int keys_t_2_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
extern "C" void score_matrix_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_score_matrix_hw(volatile void * __xlx_apatb_param_score_m_0, volatile void * __xlx_apatb_param_score_m_1, volatile void * __xlx_apatb_param_score_m_2, volatile void * __xlx_apatb_param_queries_0, volatile void * __xlx_apatb_param_queries_1, volatile void * __xlx_apatb_param_queries_2, volatile void * __xlx_apatb_param_keys_t_0, volatile void * __xlx_apatb_param_keys_t_1, volatile void * __xlx_apatb_param_keys_t_2) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_score_m_0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > score_m_0_pc_buffer(3);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "score_m_0");
  
            // push token into output port buffer
            if (AESL_token != "") {
              score_m_0_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 3; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_score_m_0)[j*4+0] = score_m_0_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_score_m_0)[j*4+1] = score_m_0_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_score_m_0)[j*4+2] = score_m_0_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_score_m_0)[j*4+3] = score_m_0_pc_buffer[i].range(31, 24).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_score_m_1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > score_m_1_pc_buffer(3);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "score_m_1");
  
            // push token into output port buffer
            if (AESL_token != "") {
              score_m_1_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 3; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_score_m_1)[j*4+0] = score_m_1_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_score_m_1)[j*4+1] = score_m_1_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_score_m_1)[j*4+2] = score_m_1_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_score_m_1)[j*4+3] = score_m_1_pc_buffer[i].range(31, 24).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_score_m_2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > score_m_2_pc_buffer(3);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "score_m_2");
  
            // push token into output port buffer
            if (AESL_token != "") {
              score_m_2_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 3; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_score_m_2)[j*4+0] = score_m_2_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_score_m_2)[j*4+1] = score_m_2_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_score_m_2)[j*4+2] = score_m_2_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_score_m_2)[j*4+3] = score_m_2_pc_buffer[i].range(31, 24).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//score_m_0
aesl_fh.touch(AUTOTB_TVIN_score_m_0);
aesl_fh.touch(AUTOTB_TVOUT_score_m_0);
//score_m_1
aesl_fh.touch(AUTOTB_TVIN_score_m_1);
aesl_fh.touch(AUTOTB_TVOUT_score_m_1);
//score_m_2
aesl_fh.touch(AUTOTB_TVIN_score_m_2);
aesl_fh.touch(AUTOTB_TVOUT_score_m_2);
//queries_0
aesl_fh.touch(AUTOTB_TVIN_queries_0);
aesl_fh.touch(AUTOTB_TVOUT_queries_0);
//queries_1
aesl_fh.touch(AUTOTB_TVIN_queries_1);
aesl_fh.touch(AUTOTB_TVOUT_queries_1);
//queries_2
aesl_fh.touch(AUTOTB_TVIN_queries_2);
aesl_fh.touch(AUTOTB_TVOUT_queries_2);
//keys_t_0
aesl_fh.touch(AUTOTB_TVIN_keys_t_0);
aesl_fh.touch(AUTOTB_TVOUT_keys_t_0);
//keys_t_1
aesl_fh.touch(AUTOTB_TVIN_keys_t_1);
aesl_fh.touch(AUTOTB_TVOUT_keys_t_1);
//keys_t_2
aesl_fh.touch(AUTOTB_TVIN_keys_t_2);
aesl_fh.touch(AUTOTB_TVOUT_keys_t_2);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_score_m_0 = 0;
// print score_m_0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_score_m_0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m_0 = 0*4;
  if (__xlx_apatb_param_score_m_0) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m_0)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_score_m_0, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.score_m_0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_score_m_0, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_score_m_1 = 0;
// print score_m_1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_score_m_1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m_1 = 0*4;
  if (__xlx_apatb_param_score_m_1) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m_1)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_score_m_1, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.score_m_1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_score_m_1, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_score_m_2 = 0;
// print score_m_2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_score_m_2, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m_2 = 0*4;
  if (__xlx_apatb_param_score_m_2) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m_2)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_score_m_2, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.score_m_2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_score_m_2, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_queries_0 = 0;
// print queries_0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_queries_0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_queries_0 = 0*4;
  if (__xlx_apatb_param_queries_0) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_queries_0)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_queries_0, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.queries_0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_queries_0, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_queries_1 = 0;
// print queries_1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_queries_1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_queries_1 = 0*4;
  if (__xlx_apatb_param_queries_1) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_queries_1)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_queries_1, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.queries_1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_queries_1, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_queries_2 = 0;
// print queries_2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_queries_2, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_queries_2 = 0*4;
  if (__xlx_apatb_param_queries_2) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_queries_2)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_queries_2, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.queries_2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_queries_2, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_keys_t_0 = 0;
// print keys_t_0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_keys_t_0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_keys_t_0 = 0*4;
  if (__xlx_apatb_param_keys_t_0) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_keys_t_0)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_keys_t_0, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.keys_t_0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_keys_t_0, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_keys_t_1 = 0;
// print keys_t_1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_keys_t_1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_keys_t_1 = 0*4;
  if (__xlx_apatb_param_keys_t_1) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_keys_t_1)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_keys_t_1, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.keys_t_1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_keys_t_1, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_keys_t_2 = 0;
// print keys_t_2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_keys_t_2, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_keys_t_2 = 0*4;
  if (__xlx_apatb_param_keys_t_2) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_keys_t_2)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_keys_t_2, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.keys_t_2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_keys_t_2, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
score_matrix_hw_stub_wrapper(__xlx_apatb_param_score_m_0, __xlx_apatb_param_score_m_1, __xlx_apatb_param_score_m_2, __xlx_apatb_param_queries_0, __xlx_apatb_param_queries_1, __xlx_apatb_param_queries_2, __xlx_apatb_param_keys_t_0, __xlx_apatb_param_keys_t_1, __xlx_apatb_param_keys_t_2);
CodeState = DUMP_OUTPUTS;
// print score_m_0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_score_m_0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m_0 = 0*4;
  if (__xlx_apatb_param_score_m_0) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m_0)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVOUT_score_m_0, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.score_m_0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_score_m_0, __xlx_sprintf_buffer.data());
}
// print score_m_1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_score_m_1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m_1 = 0*4;
  if (__xlx_apatb_param_score_m_1) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m_1)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVOUT_score_m_1, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.score_m_1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_score_m_1, __xlx_sprintf_buffer.data());
}
// print score_m_2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_score_m_2, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m_2 = 0*4;
  if (__xlx_apatb_param_score_m_2) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m_2)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVOUT_score_m_2, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(3, &tcl_file.score_m_2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_score_m_2, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
