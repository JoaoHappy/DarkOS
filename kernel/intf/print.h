#pragma once
#include <stddef.h> 
#include <stdint.h>

enum vga_color { // 16 bit de cores
	PRINT_COLOR_BLACK =  0 , 
	PRINT_COLOR_BLUE =  1 , 
	PRINT_COLOR_GREEN = 2 , 
    PRINT_COLOR_CYAN =  3 , 
	PRINT_COLOR_RED =  4 , 
    PRINT_COLOR_MAGENTA =  5 , 
	PRINT_COLOR_BROWN =  6 , 
	PRINT_COLOR_LIGHT_GREY =  7 , 
	PRINT_COLOR_DARK_GREY =  8 , 
	PRINT_COLOR_LIGHT_BLUE =  9 , 
	PRINT_COLOR_LIGHT_GREEN =  10 , 
	PRINT_COLOR_LIGHT_CYAN =  11 , 
	PRINT_COLOR_LIGHT_RED =  12 , 
	PRINT_COLOR_LIGHT_MAGENTA =  13, 
	PRINT_COLOR_LIGHT_BROWN =  14 , 
	PRINT_COLOR_WHITE =  15 , 
};


void putentryat(char c, uint8_t color, size_t x, size_t y)
void putchar(char caracter)
void writestr(const char* data, size_t size)
void printf(const char* data)
void terminal_set_color(uint8_t color) 


