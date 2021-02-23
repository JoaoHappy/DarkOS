#include <stdbool.h> 
#include <stddef.h> 
#include <stdint.h>
#include <print.h>

static const size_t Width_size_vga  = 80
static const size_t Height_size_vga = 20


static inline uint8_t vga_entry_color(enum vga_color byte_one_foreground, enum vga_color byte_two_background){
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
            const size_t index = y * Width_size_vga + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
        
    }
}

void dark_main(void)
{
	terminal_start();

	printf("DarkOS");
}