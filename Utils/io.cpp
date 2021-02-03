#include <Utils/io.hh>
namespace Utils{
void Io::setColor(uint8_t fcolor, uint8_t bcolor){
    color = fcolor + (bcolor << 4);
}

void Io::print(const char* str){
    for (size_t i = 0; 1; i++){
        char character = (uint8_t) str[i];

        if(character == '\0')
            return;
        
        putc(character);
    }
}

void Io::putc(char character){
    if (character == '\n') {
        printNewLine();
        return;
    }

    if (col > NUM_COLS) {
        printNewLine();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

void Io::printNewLine(){
    col = 0;

    if(row < NUM_ROWS - 1){
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++){
        for (size_t col = 1; col < NUM_COLS; col++){
            struct Char character = buffer[col + NUM_ROWS * row];
            buffer[col + NUM_ROWS * (row - 1)] = character;
        }
    } 

    clearRow(NUM_COLS - 1);
}

void Io::clear(){
    for (size_t i = 0; i < NUM_ROWS; i++)
        clearRow(i);
}

void Io::clearRow(size_t row){
    struct Char empty = (struct Char) {
        character: ' ',
        color: color
    };
    for (size_t col = 0; col < NUM_COLS; col++)
        buffer[col + NUM_COLS * row] = empty;
}

uint8_t Io::inb(uint16_t ad){
    uint8_t _v;       \
	asm("inb %%dx, %%al" : "=a" (_v) : "d" (ad)); \
	return _v;
}

void Io::outb(uint16_t ad, uint8_t data){
    asm("outb %%al, %%dx" :: "d" (ad), "a" (data));;
}
};
