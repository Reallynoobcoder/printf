#include "main.h"
int print_hexalow(unsigned int n)
{
    int i, j, rem, counter;
    unsigned int num_copy = n;
    char *hex_d;

    if (n == 0)
        return (_putchar('0'));

    for (counter = 0; num_copy != 0; counter++)
        num_copy /= 16;

    hex_d = malloc(counter);
    for (i = 0; n != 0; i++)
    {
        rem = 0;
        rem = n % 16;
        if (rem < 10)
            hex_d[i] = rem + '0';
        else
            hex_d[i] = rem + 'W';
        n /= 16;
    }
    for (j = i - 1; j >= 0; j--)
        _putchar(hex_d[j]);
    free(hex_d);
    return (counter);
}
int print_hex(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    return print_hexalow(num);
}
