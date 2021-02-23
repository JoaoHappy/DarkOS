#include <stdbool.h> 
#include <stddef.h> 
#include <stdint.h>

enum vga_color { // 16 bit de cores
	VGA_COLOR_BLACK =  0 , 
	VGA_COLOR_BLUE =  1 , 
	VGA_COLOR_GREEN = 2 , 
	VGA_COLOR_CYAN =  3 , 
	VGA_COLOR_RED =  4 , 
	VGA_COLOR_MAGENTA =  5 , 
	VGA_COLOR_BROWN =  6 , 
	VGA_COLOR_LIGHT_GREY =  7 , 
	VGA_COLOR_DARK_GREY =  8 , 
	VGA_COLOR_LIGHT_BLUE =  9 , 
	VGA_COLOR_LIGHT_GREEN =  10 , 
	VGA_COLOR_LIGHT_CYAN =  11 , 
	VGA_COLOR_LIGHT_RED =  12 , 
	VGA_COLOR_LIGHT_MAGENTA =  13, 
	VGA_COLOR_LIGHT_BROWN =  14 , 
	VGA_COLOR_WHITE =  15 , 
};

const size_t Width_size_vga  = 80
const size_t Height_size_vga = 20


static inline uint8_t vga_entry_color(enum vga_color byte_one_first, enum vga_color byte_two_back){
    return byte_one_first | byte_two_back << 4; // vai alocar os 4 bit das duas cores do primeiro plano e do plano de fundo do vga em um bit de 8;
}

static inline uint16_t vga_entry(unsigned char * caracter, uint8_t color){ // entrada do caracter e as cores
    return (uint16_t) caracter | (uint16_t) color << 8;
}

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_start(void){
    terminal_row   = 80
    terminal_colum = 20
    terminal_buffer (uint16_t *) 0xB8000 // endereço de video do vga tem 16 bit
    for(size_t y = 0; y < Height_size_vga; y++){
        for (size_t x = 0; x < Width_size_vga; x++)
        {
            const size_t index = y 
        }
        
    }
}