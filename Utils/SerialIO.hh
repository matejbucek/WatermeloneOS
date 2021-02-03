#pragma once
#include <Utils/io.hh>
#define ANSI_RESET "\u001b[0m"
#define ANSI_TEXT_BLACK "\u001b[30m"
#define ANSI_TEXT_RED "\u001b[31m"
#define ANSI_TEXT_GREEN "\u001b[32m"
#define ANSI_TEXT_YELLOW "\u001b[33m"
#define ANSI_TEXT_BLUE "\u001b[34m"
#define ANSI_TEXT_MAGENTA "\u001b[35m"
#define ANSI_TEXT_CYAN "\u001b[36m"
#define ANSI_TEXT_WHITE "\u001b[37m"
#define ANSI_TEXT_LIGHT_BLACK "\u001b[30;1m"
#define ANSI_TEXT_LIGHT_RED "\u001b[31;1m"
#define ANSI_TEXT_LIGHT_GREEN "\u001b[32;1m"
#define ANSI_TEXT_LIGHT_YELLOW "\u001b[33;1m"
#define ANSI_TEXT_LIGHT_BLUE "\u001b[34;1m"
#define ANSI_TEXT_LIGHT_MAGENTA "\u001b[35;1m"
#define ANSI_TEXT_LIGHT_CYAN "\u001b[36;1m"
#define ANSI_TEXT_LIGHT_WHITE "\u001b[37;1m"

#define ANSI_BACKGROUND_BLACK "\u001b[40m"
#define ANSI_BACKGROUND_RED "\u001b[41m"
#define ANSI_BACKGROUND_GREEN "\u001b[42m"
#define ANSI_BACKGROUND_YELLOW "\u001b[43m"
#define ANSI_BACKGROUND_BLUE "\u001b[44m"
#define ANSI_BACKGROUND_MAGENTA "\u001b[45m"
#define ANSI_BACKGROUND_CYAN "\u001b[46m"
#define ANSI_BACKGROUND_WHITE "\u001b[47m"
#define ANSI_BACKGROUND_LIGHT_BLACK "\u001b[40;1m"
#define ANSI_BACKGROUND_LIGHT_RED "\u001b[41;1m"
#define ANSI_BACKGROUND_LIGHT_GREEN "\u001b[42;1m"
#define ANSI_BACKGROUND_LIGHT_YELLOW "\u001b[43;1m"
#define ANSI_BACKGROUND_LIGHT_BLUE "\u001b[44;1m"
#define ANSI_BACKGROUND_LIGHT_MAGENTA "\u001b[45;1m"
#define ANSI_BACKGROUND_LIGHT_CYAN "\u001b[46;1m"
#define ANSI_BACKGROUND_LIGHT_WHITE "\u001b[47;1m"

namespace Utils{
    enum ANSI : int{
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37,
        RESET = 0
    };
    class SerialIO{
        Io *io;
        uint16_t port;
        public:	
        SerialIO(Io *io, uint16_t port){
            this->io = io;
            this->port = port;
        };
        //virtual ~SerialIO() = 0;
        int init();
        int received();
        char read();
        int isTransmitEmpty();
        void write(char character);
        void print(const char * str);
        void println(const char * str);
        void setColor(const char* color);
        void unsetColor();
        void printError(const char * str);
        void printDebug(const char * str);
        void printSuccess(const char * str);
    };
};