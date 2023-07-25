#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * struct convert - Convert specifier mapping and its corresponding function.
 *
 * @spef: The conversion specifier string.
 * @f_ptr: Pointer to the corresponding function that handles the conversion.
 */
typedef struct convert
{
	char *spef;
	int (*f_ptr)(va_list);
} trans;


int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list args);
int print_percent(va_list);
int print_integer(va_list);
int print_binary(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_octal(va_list args);
int print_unsigned(va_list args);
#define ERROR -1

#endif
