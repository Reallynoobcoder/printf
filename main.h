#ifndef  MAIN_H
#define  MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct convert
{
    char *spef;
    int (*f_ptr)(va_list);
} trans;


int _putchar(char c);
int _printf(const char *format, ...);
int parser(const char *format, trans formatMap[], va_list args);
int p_char(va_list);
int p_string(va_list args);
int p_percent(va_list);
int p_integer(va_list);
#define ERROR -1

#endif
