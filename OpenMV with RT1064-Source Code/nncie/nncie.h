#define CI_CFG_TENSOR_ALIGN		8
#define CI_CFG_TENSOR_FORMAT	0	// 0=[H][W][C], 1=[C][H][W]
typedef struct _CI_CmdBuf {
	uint8_t in;	// Index of buffer that contains input
	uint8_t ou;	// Index of buffer that contains output
	uint8_t wt;	// Index of buffer that contains weight
	uint8_t gn;	// different command have different usage
	// all offsets must be aligned to CI_CFG_TENSOR_ALIGN
	uint32_t ofsIn;
	uint32_t ofsOt;
	uint32_t ofsWt;
	uint32_t ofsGn;
}CI_CmdBuf;

typedef enum _ci_opcode_enum {
	ciop_dat_feed,
	ciop_mem_new,
	ciop_mem_del,
	ciop_mem_cpy,
	ciop_tns_matmul,
	ciop_nn_fc,
	ciop_nn_conv,
	ciop_nn_lstm,
	ciop_nn_gru,
	ciop_ctl_b
	
	ciop_ptws_add,
}ci_opcode_enum;

typedef struct _CI_Cmd_t {
	union {
		uint16_t ndx16;
		struct {
			uint8_t ndx8[2];
		};
	};
	enum_opcode opCode;
	uint8_t flags;
	CI_CmdBuf buf;
	
}CI_Cmd_t;

typedef struct _CI_Conv


/* cifar-10
in1Size = 32*32*3
ot1Size = 32*32*32
wtMaxSize= 32*64*5*5
ci_mem_new(0x0101, bufIn=1, size=wtMaxSize)
ci_mem_new(0x0101, bufIn=2, size=ot1Size)
ci_dat_feed(0x0201, bufIn=1, bufOfs=0) 
wt1Size = 3*32*5*5 + 32
ci_mem_load(0x0202, bufIn=1, bufOfs=in1Size, wtOfs=0, size=wt1Size)
ot1Ofs = in1Size+wt1Size
ci_nn_conv(0x0301, bufIn=1, inOfs=0, bufWt=1, wtOfs= in1Size, bufOt=1, otOfs=ot1Ofs, pool=(pool_max,2,2,1), acti=acti_relu, bufIn=1, kW=5, kH=5, p=2, s=1, lshf=9, rshf=0)
ci_nn_conv(0x0401, bufIn=1, inOfs=ot1Ofs, bufWt=1, wtOfs= in1Size, bufOt=1, otOfs=in1Size+wt1Size, pool=(pool_max,2,2,1), acti=acti_relu, kW=5, kH=5, p=2, s=1, lshf=9, rshf=0)

*/