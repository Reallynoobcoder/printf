#ifndef  MAIN_H
#define  MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

struct convert
{
    char *sym;
    int (*f)(va_list);
};
typedef struct convert conver_t;


int _putchar(char c);
int _printf(const char *format, ...);
int parser(const char *format, conver_t funct_list[], va_list args);
int p_char(va_list);
int p_string(va_list args);
int p_percent(va_list);
int p_integer(va_list);
#define ERROR -1

#endif
