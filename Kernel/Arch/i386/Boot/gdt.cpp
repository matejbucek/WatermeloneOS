#include <Kernel/Arch/i386/Boot/gdt.hh>
#include <Utils/memory.hh>

using Utils::memcpy;
struct gdt_entry gdt[3];
struct gdtr _gp;


void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
	/* Setup the descriptor base access */
	gdt[num].base_low = (base & 0xFFFF);
	gdt[num].base_middle = (base >> 16) & 0xFF;
	gdt[num].base_high = (base >> 24) & 0xFF;

	/* Setup the descriptor limits */
	gdt[num].limit_low = (limit & 0xFFFF);
	gdt[num].granularity = ((limit >> 16) & 0x0F);

	/* Finally, set up the granularity and access flags */
	gdt[num].granularity |= (gran & 0xF0);
	gdt[num].access = access;
}

void gdt_install()
{
	_gp.limit = (sizeof(struct gdt_entry) * 6) - 1;
	_gp.base = (unsigned long int)&gdt;
	//gdt_set_gate(0, 0, 0, 0, 0);
    gdt[0].base_low = 0;
    gdt[0].base_middle = 0;
    gdt[0].base_high = 0;
    gdt[0].limit_low = 0;
    gdt[0].granularity = 0;
    gdt[0].access = 0;

    //gdt[1].base_low = 0;
    //gdt[1].base_middle = 0;
    //gdt[1].base_high = 0;
    //gdt[1].limit_low = 0;
    //gdt[1].granularity = 0x20;
    //gdt[1].access = 0x9C;

    
}