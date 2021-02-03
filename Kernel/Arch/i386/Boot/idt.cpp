#include <Kernel/Arch/i386/Boot/idt.hh>
#include <Utils/types.hh>
#include <Utils/memory.hh>
#include <Utils/libc.hh>
#include <Utils/io.hh>
#include <Utils/SerialIO.hh>

extern Utils::SerialIO *serial;

extern IDT64 _idt[256];
extern "C" u64 isr0; 
extern "C" u64 isr1; 


void InitializeIDT(){
		_idt[0].zero = 0;
		_idt[0].offset_low = (u16)(((u64)&isr0 & 0x000000000000ffff));
		_idt[0].offset_mid = (u16)(((u64)&isr0 & 0x00000000ffff0000) >> 16);
		_idt[0].offset_high = (u32)(((u64)&isr0 & 0xffffffff00000000) >> 32);
		_idt[0].ist = 0;
		_idt[0].selector = 0x08;
		_idt[0].types_attr = 0x8e;
	for(u64 t = 1; t < 256; t++){
		_idt[t].zero = 0;
		_idt[t].offset_low = (u16)(((u64)&isr1 & 0x000000000000ffff));
		_idt[t].offset_mid = (u16)(((u64)&isr1 & 0x00000000ffff0000) >> 16);
		_idt[t].offset_high = (u32)(((u64)&isr1 & 0xffffffff00000000) >> 32);
		_idt[t].ist = 0;
		_idt[t].selector = 0x08;
		_idt[t].types_attr = 0x8e;
	}

	io.outb(0x21, 0xfd);
	io.outb(0xa1, 0xff);

	//io.outb(0x20, 0x11);
  	//io.outb(0xA0, 0x11);
	//io.outb(0x21, 0x20);
	//io.outb(0xA1, 0x28);
	//io.outb(0x21, 0x04);
	//io.outb(0xA1, 0x02);
	//io.outb(0x21, 0x01);
	//io.outb(0xA1, 0x01);
	//io.outb(0x21, 0x0);
	//io.outb(0xA1, 0x0);
	LoadIDT();
}

extern "C" void isr0_handler(){
	serial->printDebug("Nula");
	io.outb(0x20, 0x20);
	io.outb(0xa0, 0x20);
}

extern "C" void _fault_handler(unsigned int b, unsigned int c){
	switch(b){
		case 0:
			serial->printError("Devided by zero");
			break;
		case 1:
			serial->printSuccess("Keyboard");
			io.inb(0x60);
			break;
		default:
			serial->printDebug("Other");	
	}
	io.outb(0x20, 0x20);
	io.outb(0xa0, 0x20);
	//serial->printSuccess("Handler");
	//char a[32];
	//Utils::itoa(a, b, 16);
	//serial->printSuccess(a);
	//char d[32];
	//Utils::itoa(d, c, 16);
	//serial->printSuccess(d);
	//isr1_handler();
}