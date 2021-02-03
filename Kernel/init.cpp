#include <Utils/ArrayList.hh>
#include <Utils/io.hh>
#include <Utils/string.hh>
#include <Kernel/boot.hh>
#include <Utils/types.hh>
#include <Utils/keyboard.hh>
#include <Utils/SerialIO.hh>
#include <Kernel/Arch/i386/Boot/gdt.hh>
#include <Kernel/Arch/i386/Boot/idt.hh>

using Utils::Io;
using Utils::SerialIO;
using Utils::strlen;
using Utils::strcmp;
using Utils::strcpy;
using Utils::String;
Io io;
SerialIO *serial;

//GDT & Paging is set up in assembly, because of
//64bit boot. This function is called after booting
//to 64bit.
//IDT is defined in assembly, but initialized in idt.cpp.
extern "C" void kernel_init(){
    io.clear();
    io.setColor(PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);
    io.print("Welcome to WatermeloneOS!\n");
    io.setColor(PRINT_COLOR_LIGHT_CYAN, PRINT_COLOR_BLACK);
    io.print("This project is beeing developed by Matej Bucek.\n");
    SerialIO s(&io, 0x3f8);
    serial = &s;
    serial->init();

    
    InitializeIDT();
    //isrs_install();
    

    serial->printDebug("DONE");
    for(;;){

    }
};
