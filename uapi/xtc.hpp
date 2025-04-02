#include "../include/uapi.h"
// #include "./cpp_uapi.hpp"
#include <map>
#include <list>

struct xtc_st {
    __u16   tabl_ndx;
    struct {
        __u8 rex, addr, oper;
    } pfx;

    struct {
        OperType    t;
        __u32       size;
    } op[4];
    __u8    op_count;
    __u8    sc[15];
    __u8    sc_len;
    instr *in;
};

class x_t_c {
public:
    x_t_c();
    __s8 get(__u8 *sc, insn_t& in, __u64 op[4]);
private:
    void insert(instr *in);
};
