#pragma once
#include <Utils/types.hh>

#define GDTSIZE 0xFF
#define GDTBASE 0x00000800	

struct gdtr{
   	u16 limit;
	u32 base;
}__attribute__ ((packed));

struct gdt_entry{
   	u16 limit_low;
	u16 base_low;
	u8 base_middle;
	u8 access;
	u8 granularity;
	u8 base_high;
}__attribute__ ((packed));
extern "C" void gdt_flush();
extern "C" void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern "C" void gdt_install();
extern "C" void _gdt_flush();