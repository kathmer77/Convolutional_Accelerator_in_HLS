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
#define AUTOTB_TVIN_score_m "../tv/cdatafile/c.score_matrix.autotvin_score_m.dat"
#define AUTOTB_TVOUT_score_m "../tv/cdatafile/c.score_matrix.autotvout_score_m.dat"
// wrapc file define:
#define AUTOTB_TVIN_queries "../tv/cdatafile/c.score_matrix.autotvin_queries.dat"
#define AUTOTB_TVOUT_queries "../tv/cdatafile/c.score_matrix.autotvout_queries.dat"
// wrapc file define:
#define AUTOTB_TVIN_keys_t "../tv/cdatafile/c.score_matrix.autotvin_keys_t.dat"
#define AUTOTB_TVOUT_keys_t "../tv/cdatafile/c.score_matrix.autotvout_keys_t.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_score_m "../tv/rtldatafile/rtl.score_matrix.autotvout_score_m.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_queries "../tv/rtldatafile/rtl.score_matrix.autotvout_queries.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_keys_t "../tv/rtldatafile/rtl.score_matrix.autotvout_keys_t.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  score_m_depth = 0;
  queries_depth = 0;
  keys_t_depth = 0;
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
  total_list << "{score_m " << score_m_depth << "}\n";
  total_list << "{queries " << queries_depth << "}\n";
  total_list << "{keys_t " << keys_t_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int score_m_depth;
    int queries_depth;
    int keys_t_depth;
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
extern "C" void score_matrix_hw_stub_wrapper(volatile void *, volatile void *, volatile void *);

extern "C" void apatb_score_matrix_hw(volatile void * __xlx_apatb_param_score_m, volatile void * __xlx_apatb_param_queries, volatile void * __xlx_apatb_param_keys_t) {
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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_score_m);
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
          std::vector<sc_bv<32> > score_m_pc_buffer(9);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "score_m");
  
            // push token into output port buffer
            if (AESL_token != "") {
              score_m_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 9; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_score_m)[j*4+0] = score_m_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_score_m)[j*4+1] = score_m_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_score_m)[j*4+2] = score_m_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_score_m)[j*4+3] = score_m_pc_buffer[i].range(31, 24).to_int64();
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
//score_m
aesl_fh.touch(AUTOTB_TVIN_score_m);
aesl_fh.touch(AUTOTB_TVOUT_score_m);
//queries
aesl_fh.touch(AUTOTB_TVIN_queries);
aesl_fh.touch(AUTOTB_TVOUT_queries);
//keys_t
aesl_fh.touch(AUTOTB_TVIN_keys_t);
aesl_fh.touch(AUTOTB_TVOUT_keys_t);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_score_m = 0;
// print score_m Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_score_m, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m = 0*4;
  if (__xlx_apatb_param_score_m) {
    for (int j = 0  - 0, e = 9 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_score_m, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(9, &tcl_file.score_m_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_score_m, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_queries = 0;
// print queries Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_queries, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_queries = 0*4;
  if (__xlx_apatb_param_queries) {
    for (int j = 0  - 0, e = 9 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_queries)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_queries, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(9, &tcl_file.queries_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_queries, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_keys_t = 0;
// print keys_t Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_keys_t, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_keys_t = 0*4;
  if (__xlx_apatb_param_keys_t) {
    for (int j = 0  - 0, e = 9 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_keys_t)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVIN_keys_t, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(9, &tcl_file.keys_t_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_keys_t, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
score_matrix_hw_stub_wrapper(__xlx_apatb_param_score_m, __xlx_apatb_param_queries, __xlx_apatb_param_keys_t);
CodeState = DUMP_OUTPUTS;
// print score_m Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_score_m, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_score_m = 0*4;
  if (__xlx_apatb_param_score_m) {
    for (int j = 0  - 0, e = 9 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_score_m)[j];

    std::string s(__xlx_tmp_lv.to_string(SC_HEX));
    aesl_fh.write(AUTOTB_TVOUT_score_m, s.append("\n")); 
      }
  }
}
  tcl_file.set_num(9, &tcl_file.score_m_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_score_m, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
