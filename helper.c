#include "main.h"
/*
 * no zhi(
 */

int p_char(va_list args)
{
    char value;

    value = va_arg(args, int);
    _putchar(value);
    return (1);
}



int p_string(va_list args)
{
    int i;
    const char *s;

    s = va_arg(args, const char *);
    if (s == NULL)
        s = "(null)";
    for (i = 0; s[i] != '\0'; i++)
        _putchar(s[i]);
    return (i);
}



int p_percent(__attribute__((unused)) va_list args)
{
    _putchar('%');
    return (1);
}

