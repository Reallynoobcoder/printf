#ifndef  MAIN_H
#define  MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int _printf(const char *format, ...);
void print_char(va_list args);
void print_string(va_list args);
void print_percent(va_list args);
void print_unknown(va_list args);

#endif
