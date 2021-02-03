#pragma once
#include <Utils/types.hh>
//#include <Utils/SerialIO.hh>
/* Defines an IDT entry */
struct IDT64
{
    u16 offset_low;
    u16 selector;
    u8 ist;
    u8 types_attr;
    u16 offset_mid;
    u32 offset_high;
    u32 zero;
} __attribute__((packed));

extern "C" void LoadIDT();
void InitializeIDT();