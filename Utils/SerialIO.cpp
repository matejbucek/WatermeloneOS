#include <Utils/SerialIO.hh>
namespace Utils{
    int SerialIO::init(){
        io->outb(port + 1, 0x00);    // Disable all interrupts
        io->outb(port + 3, 0x80);    // Enable DLAB (set baud rate divisor)
        io->outb(port + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
        io->outb(port + 1, 0x00);    //                  (hi byte)
        io->outb(port + 3, 0x03);    // 8 bits, no parity, one stop bit
        io->outb(port + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
        io->outb(port + 4, 0x0B);    // IRQs enabled, RTS/DSR set
        io->outb(port + 4, 0x1E);    // Set in loopback mode, test the serial chip
        io->outb(port + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)
 
        // Check if serial is faulty (i.e: not same byte as sent)
        if(io->inb(port + 0) != 0xAE) {
            return 1;
        }
        
        // If serial is not faulty set it in normal operation mode
        // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
        io->outb(port + 4, 0x0F);
        return 0;
    }

    int SerialIO::received(){
        return io->inb(port + 5) & 1;
    }

    char SerialIO::read(){
        while (read() == 0);
        return io->inb(port);
    } 

    int SerialIO::isTransmitEmpty(){
        return io->inb(port + 5) & 0x20;
    }

    void SerialIO::write(char character){
        while (isTransmitEmpty() == 0);
        io->outb(port, character);
    }

    void SerialIO::print(const char * str){
        for (size_t i = 0; 1; i++)
        {
            char character = str[i];

            if(character == '\0')
                return;

            write(character);
        }
        
    }

    void SerialIO::println(const char * str){
        print(str);
        print("\n");
    }

    void SerialIO::setColor(const char* color){
        print(color);
    }

    void SerialIO::unsetColor(){
        setColor(ANSI_RESET);
    }

    void SerialIO::printError(const char * str){
        setColor(ANSI_TEXT_RED);
        println(str);
        unsetColor();
    }

    void SerialIO::printDebug(const char * str){
        setColor(ANSI_TEXT_LIGHT_CYAN);
        println(str);
        unsetColor();
    }

    void SerialIO::printSuccess(const char * str){
        setColor(ANSI_TEXT_LIGHT_GREEN);
        println(str);
        unsetColor();
    }

};