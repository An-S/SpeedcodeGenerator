#ifndef __OPC6502_H__
#define __OPC6502_H__

#include <stdint.h>

typedef enum {a,b} MOS6502_1ByteOpcode_t;
typedef enum {c,d} MOS6502_2ByteOpcode_t;
typedef enum {e,f} MOS6502_3ByteOpcode_t;

typedef struct
{
	MOS6502_1ByteOpcode_t cmd;
} MOS6502_1ByteCmd_t;

typedef struct
{
	MOS6502_2ByteOpcode_t cmd;
	uint8_t arg;
} MOS6502_2ByteCmd_t;

typedef struct
{
	MOS6502_3ByteOpcode_t cmd;
	uint16_t arg;
} MOS6502_3ByteCmd_t;
 
//CODES 00-0F

#define OPC6502_BRK  0x00
#define OPC6502_ORA_XIND  0x01
#define OPC6502_HLT  0x02
#define OPC6502_KIL  0x02
#define OPC6502_JAM  0x02
#define OPC6502_SLO_XIND  0x03
#define OPC6502_ASO_XIND  0x03
#define OPC6502_NOP_ZP  0x04
#define OPC6502_ORA_ZP  0x05
#define OPC6502_ASL_ZP  0x06
#define OPC6502_SLO_ZP  0x07
#define OPC6502_ASO_ZP  0x07
#define OPC6502_PHP  0x08
#define OPC6502_ORA_IMM  0x09
#define OPC6502_ASL  0x0A
#define OPC6502_ANC_IMM  0x0B
#define OPC6502_AAC_IMM  0x0B
#define OPC6502_NOP_ABS  0x0C
#define OPC6502_ORA_ABS  0x0D
#define OPC6502_ASL_ABS  0x0E
#define OPC6502_SLO_ABS  0x0F
#define OPC6502_ASO_ABS  0x0F

//CODES 10-1F
#define OPC6502_BPL  0x10
#define OPC6502_ORA_INDY  0x11
#define OPC6502_HLT2  0x12
#define OPC6502_KIL2  0x12
#define OPC6502_JAM2  0x12
#define OPC6502_SLO_INDY  0x13
#define OPC6502_ASO_INDY  0x13
#define OPC6502_NOP_ZPX  0x14
#define OPC6502_ORA_ZPX  0x15
#define OPC6502_ASL_ZPX  0x16
#define OPC6502_SLO_ZPX  0x17
#define OPC6502_ASO_ZPX  0x17
#define OPC6502_CLC  0x18
#define OPC6502_ORA_ABSY  0x19
#define OPC6502_NOP2  0x1A
#define OPC6502_SLO_ABSY  0x1B
#define OPC6502_ASO_ABSY  0x1B
#define OPC6502_NOP_ABSX  0x1C
#define OPC6502_ORA_ABSX  0x1D
#define OPC6502_ASL_ABSX  0x1E
#define OPC6502_SLO_ABSX  0x1F
#define OPC6502_ASO_ABSX  0x1F

//CODES 20-2F
#define OPC6502_JSR_ABS  0x20
#define OPC6502_AND_XIND  0x21
#define OPC6502_HLT3  0x22
#define OPC6502_KIL3  0x22
#define OPC6502_JAM3  0x22
#define OPC6502_RLA_XIND  0x23
#define OPC6502_BIT_ZP  0x24
#define OPC6502_AND_ZP  0x25
#define OPC6502_ROL_ZP  0x26
#define OPC6502_RLA_ZP  0x27
#define OPC6502_PLP  0x28
#define OPC6502_AND_IMM  0x29
#define OPC6502_ROL  0x2A
#define OPC6502_ANC_IMM2  0x2B
#define OPC6502_AAC_IMM2  0x2B
#define OPC6502_BIT_ABS  0x2C
#define OPC6502_AND_ABS  0x2D
#define OPC6502_ROL_ABS  0x2E
#define OPC6502_RLA_ABS  0x2F

//CODES 30-3F
#define OPC6502_BMI  0x30
#define OPC6502_AND_INDY  0x31
#define OPC6502_HLT4  0x32
#define OPC6502_KIL4  0x32
#define OPC6502_JAM4  0x32
#define OPC6502_RLA_INDY  0x33
#define OPC6502_NOP_ZPX2  0x34
#define OPC6502_AND_ZPX  0x35
#define OPC6502_ROL_ZPX  0x36
#define OPC6502_RLA_ZPX  0x37
#define OPC6502_SEC  0x38
#define OPC6502_AND_ABSY  0x39
#define OPC6502_NOP3  0x3A
#define OPC6502_RLA_ABSY  0x3B
#define OPC6502_NOP_ABSX2  0x3C
#define OPC6502_AND_ABSX  0x3D
#define OPC6502_ROL_ABSX  0x3E
#define OPC6502_RLA_ABSX  0x3F

//CODES 40-4F
#define OPC6502_RTI  0x40
#define OPC6502_EOR_XIND  0x41
#define OPC6502_HLT5  0x42
#define OPC6502_KIL5  0x42
#define OPC6502_JAM5  0x42
#define OPC6502_SRE_XIND  0x43
#define OPC6502_LSE_XIND  0x43
#define OPC6502_NOP_ZP2  0x44
#define OPC6502_EOR_ZP  0x45
#define OPC6502_LSR_ZP  0x46
#define OPC6502_SRE_ZP  0x47
#define OPC6502_LSE_ZP  0x47
#define OPC6502_PHA  0x48
#define OPC6502_EOR_IMM  0x49
#define OPC6502_LSR  0x4A
#define OPC6502_ALR_IMM  0x4B
#define OPC6502_ASR_IMM  0x4B
#define OPC6502_JMP_ABS  0x4C
#define OPC6502_EOR_ABS  0x4D
#define OPC6502_LSR_ABS  0x4E
#define OPC6502_SRE_ABS  0x4F
#define OPC6502_LSE_ABS  0x4F

//CODES 50-5F
#define OPC6502_BVC  0x50
#define OPC6502_EOR_INDY  0x51
#define OPC6502_HLT6  0x52
#define OPC6502_KIL6  0x52
#define OPC6502_JAM6  0x52
#define OPC6502_SRE_INDY  0x53
#define OPC6502_LSE_INDY  0x53
#define OPC6502_NOP_ZPX3  0x54
#define OPC6502_EOR_ZPX  0x55
#define OPC6502_LSR_ZPX  0x56
#define OPC6502_SRE_ZPX  0x57
#define OPC6502_LSE_ZPX  0x57
#define OPC6502_CLI  0x58
#define OPC6502_EOR_ABSY  0x59
#define OPC6502_NOP4  0x5A
#define OPC6502_SRE_ABSY  0x5B
#define OPC6502_LSE_ABSY  0x5B
#define OPC6502_NOP_ABSX3  0x5C
#define OPC6502_EOR_ABSX  0x5D
#define OPC6502_LSR_ABSX  0x5E
#define OPC6502_SRE_ABSX  0x5F
#define OPC6502_LSE_ABSX  0x5F


//CODES 60-6F
#define OPC6502_RTS  0x60
#define OPC6502_ADC_XIND  0x61
#define OPC6502_HLT7  0x62
#define OPC6502_KIL7  0x62
#define OPC6502_JAM7  0x62
#define OPC6502_RRA_XIND  0x63
#define OPC6502_NOP_ZP3  0x64
#define OPC6502_ADC_ZP  0x65
#define OPC6502_ROR_ZP  0x66
#define OPC6502_RRA_ZP  0x67
#define OPC6502_PLA  0x68
#define OPC6502_ADC_IMM  0x69
#define OPC6502_ROR  0x6A
#define OPC6502_ARR_IMM  0x6B
#define OPC6502_JMP_IND  0x6C
#define OPC6502_ADC_ABS  0x6D
#define OPC6502_ROR_ABS  0x6E
#define OPC6502_RRA_ABS  0x6F


//CODES 70-7F
#define OPC6502_BVS  0x70
#define OPC6502_ADC_INDY  0x71
//#define OPC6502_HLT  0x72
//#define OPC6502_KIL  0x72
//#define OPC6502_JAM  0x72
#define OPC6502_RRA_INDY  0x73
//#define OPC6502_NOP_ZPX  0x74
#define OPC6502_ADC_ZPX  0x75
#define OPC6502_ROR_ZPX  0x76
#define OPC6502_RRA_ZPX  0x77
#define OPC6502_SEI  0x78
#define OPC6502_ADC_ABSY  0x79
//#define OPC6502_NOP  0x7A
#define OPC6502_RRA_ABSY  0x7B
//#define OPC6502_NOP_ABSX  0x7C
#define OPC6502_ADC_ABSX  0x7D
#define OPC6502_ROR_ABSX  0x7E
#define OPC6502_RRA_ABSX  0x7F


//CODES 80-8F
#define OPC6502_NOP_IMM  0x80
#define OPC6502_STA_XIND  0x81
//#define OPC6502_NOP_IMM  0x82
#define OPC6502_SAX_XIND  0x83
#define OPC6502_STY_ZP  0x84
#define OPC6502_STA_ZP  0x85
#define OPC6502_STX_ZP  0x86
#define OPC6502_SAX_ZP  0x87
#define OPC6502_DEY  0x88
//#define OPC6502_NOP_IMM  0x89
#define OPC6502_TXA  0x8A
#define OPC6502_XAA_IMM  0x8B
#define OPC6502_ANE_IMM  0x8B
#define OPC6502_STY_ABS  0x8C
#define OPC6502_STA_ABS  0x8D
#define OPC6502_STX_ABS  0x8E
#define OPC6502_SAX_ABS  0x8F


//CODES 90-9F
#define OPC6502_BCC  0x90
#define OPC6502_STA_INDY  0x91
//#define OPC6502_HLT  0x92
//#define OPC6502_KIL  0x92
//#define OPC6502_JAM  0x92
#define OPC6502_AHX_INDY  0x93
#define OPC6502_SAH_INDY  0x93
#define OPC6502_AXA_INDY  0x93
#define OPC6502_STY_ZPX 0x94
#define OPC6502_STA_ZPX  0x95
#define OPC6502_STX_ZPY  0x96
#define OPC6502_SAX_ZPY  0x97
#define OPC6502_TYA  0x98
#define OPC6502_STA_ABSY  0x99
#define OPC6502_TXS  0x9A
#define OPC6502_TAS_ABSY  0x9B
#define OPC6502_XAS_ABSY  0x9B
#define OPC6502_SHS_ABSY  0x9B
#define OPC6502_SHY_ABSX  0x9C
#define OPC6502_SYA_ABSX  0x9C
#define OPC6502_STA_ABSX  0x9D
#define OPC6502_SHX_ABSY  0x9E
#define OPC6502_SXA_ABSY  0x9E
#define OPC6502_AHX_ABSY  0x9F
#define OPC6502_SAH_ABSY  0x9F
#define OPC6502_AXA_ABSY  0x9F


//CODES A0-AF
#define OPC6502_LDY_IMM  0xA0
#define OPC6502_LDA_XIND  0xA1
#define OPC6502_LDX_IMM  0xA2
#define OPC6502_LAX_XIND  0xA3
#define OPC6502_LDY_ZP  0xA4
#define OPC6502_LDA_ZP  0xA5
#define OPC6502_LDX_ZP  0xA6
#define OPC6502_LAX_ZP  0xA7
#define OPC6502_TAY  0xA8
#define OPC6502_LDA_IMM  0xA9
#define OPC6502_TAX  0xAA
#define OPC6502_LAX_IMM  0xAB
#define OPC6502_LDY_ABS  0xAC
#define OPC6502_LDA_ABS  0xAD
#define OPC6502_LDX_ABS  0xAE
#define OPC6502_LAX_ABS  0xAF


//CODES B0-BF
#define OPC6502_BCS  0xB0
#define OPC6502_LDA_INDY  0xB1
//#define OPC6502_HLT  0xB2
//#define OPC6502_KIL  0xB2
//#define OPC6502_JAM  0xB2
#define OPC6502_LAX_INDY  0xB3
#define OPC6502_LDY_ZPX  0xB4
#define OPC6502_LDA_ZPX  0xB5
#define OPC6502_LDX_ZPY  0xB6
#define OPC6502_LAX_ZPY  0xB7
#define OPC6502_CLV  0xB8
#define OPC6502_LDA_ABSY  0xB9
#define OPC6502_TSX  0xBA
#define OPC6502_LAS_ABSY  0xBB
#define OPC6502_LAR_ABSY  0xBB
#define OPC6502_LAE_ABSY  0xBB
#define OPC6502_LDY_ABSX  0xBC
#define OPC6502_LDA_ABSX  0xBD
#define OPC6502_LDX_ABSY  0xBE
#define OPC6502_LAX_ABSY  0xBF


//CODES C0-CF
#define OPC6502_CPY_IMM  0xC0
#define OPC6502_CMP_XIND  0xC1
//#define OPC6502_NOP_IMM  0xC2
#define OPC6502_DCP_XIND  0xC3
#define OPC6502_CPY_ZP  0xC4
#define OPC6502_CMP_ZP  0xC5
#define OPC6502_DEC_ZP  0xC6
#define OPC6502_DCP_ZP  0xC7
#define OPC6502_INY  0xC8
#define OPC6502_CMP_IMM  0xC9
#define OPC6502_DEX  0xCA
#define OPC6502_AXS_IMM  0xCB
#define OPC6502_AAX_IMM  0xCB
#define OPC6502_CPY_ABS  0xCC
#define OPC6502_CMP_ABS  0xCD
#define OPC6502_DEC_ABS  0xCE
#define OPC6502_DCP_ABS  0xCF


//CODES D0-DF
#define OPC6502_BNE  0xD0
#define OPC6502_CMP_INDY  0xD1
//#define OPC6502_HLT  0xD2
//#define OPC6502_KIL  0xD2
//#define OPC6502_JAM  0xD2
#define OPC6502_DCP_INDY  0xD3
//#define OPC6502_NOP_ZPX  0xD4
#define OPC6502_CMP_ZPX  0xD5
#define OPC6502_DEC_ZPX  0xD6
#define OPC6502_DCP_ZPX  0xD7
#define OPC6502_CLD  0xD8
#define OPC6502_CMP_ABSY  0xD9
//#define OPC6502_NOP  0xDA
#define OPC6502_DCP_ABSY  0xDB
//#define OPC6502_NOP_ABSX  0xDC
#define OPC6502_CMP_ABSX  0xDD
#define OPC6502_DEC_ABSX  0xDE
#define OPC6502_DCP_ABSX  0xDF


//CODES E0-EF
#define OPC6502_CPX_IMM  0xE0
#define OPC6502_SBC_XIND  0xE1
//#define OPC6502_NOP_IMM  0xE2
#define OPC6502_ISC_XIND  0xE3
#define OPC6502_ISB_XIND  0xE3
#define OPC6502_CPX_ZP  0xE4
#define OPC6502_SBC_ZP  0xE5
#define OPC6502_INC_ZP  0xE6
#define OPC6502_ISC_ZP  0xE7
#define OPC6502_ISB_ZP  0xE7
#define OPC6502_INX  0xE8
#define OPC6502_SBC_IMM  0xE9
#define OPC6502_NOP  0xEA
//#define OPC6502_SBC_IMM  0xEB
#define OPC6502_CPX_ABS  0xEC
#define OPC6502_SBC_ABS  0xED
#define OPC6502_INC_ABS  0xEE
#define OPC6502_ISC_ABS  0xEF
#define OPC6502_ISB_ABS  0xEF


//CODES F0-FF
#define OPC6502_BEQ  0xF0
#define OPC6502_SBC_INDY  0xF1
//#define OPC6502_HLT  0xF2
//#define OPC6502_KIL  0xF2
//#define OPC6502_JAM  0xF2
#define OPC6502_ISC_INDY  0xF3
#define OPC6502_ISB_INDY  0xF3
//#define OPC6502_NOP_ZPX  0xF4
#define OPC6502_SBC_ZPX  0xF5
#define OPC6502_INC_ZPX  0xF6
#define OPC6502_ISC_ZPX  0xF7
#define OPC6502_ISB_ZPX  0xF7
#define OPC6502_SED  0xF8
#define OPC6502_SBC_ABSY  0xF9
//#define OPC6502_NOP  0xFA
#define OPC6502_ISC_ABSY  0xFB
#define OPC6502_ISB_ABSY  0xFB
//#define OPC6502_NOP_ABSX  0xFC
#define OPC6502_SBC_ABSX  0xFD
#define OPC6502_INC_ABSX  0xFE
#define OPC6502_ISC_ABSX  0xFF
#define OPC6502_ISB_ABSX  0xFF

#endif