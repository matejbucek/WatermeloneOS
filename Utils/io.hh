#pragma once
#include <Utils/libc.hh>
enum{
    PRINT_COLOR_BLACK = 0,
	PRINT_COLOR_BLUE = 1,
	PRINT_COLOR_GREEN = 2,
	PRINT_COLOR_CYAN = 3,
	PRINT_COLOR_RED = 4,
	PRINT_COLOR_MAGENTA = 5,
	PRINT_COLOR_BROWN = 6,
	PRINT_COLOR_LIGHT_GRAY = 7,
	PRINT_COLOR_DARK_GRAY = 8,
	PRINT_COLOR_LIGHT_BLUE = 9,
	PRINT_COLOR_LIGHT_GREEN = 10,
	PRINT_COLOR_LIGHT_CYAN = 11,
	PRINT_COLOR_LIGHT_RED = 12,
	PRINT_COLOR_PINK = 13,
	PRINT_COLOR_YELLOW = 14,
	PRINT_COLOR_WHITE = 15,
};
namespace Utils{
const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;
struct Char {
    uint8_t character;
    uint8_t color;
};
class Io{
    struct Char* buffer = (struct Char*) 0xb8000;
    size_t col = 0;
    size_t row = 0;
    uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;
public:
    void print(const char* str);
    void putc(const char character);
    void clear();
    void setColor(uint8_t fcolor, uint8_t bcolor);
	uint8_t inb(uint16_t ad);
	void outb(uint16_t port, uint8_t data);
    void printNewLine();

private:
    void clearRow(size_t row);
};
};
extern Utils::Io io;