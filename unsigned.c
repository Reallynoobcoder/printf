#include "main.h"

/**
 * print_unsig - Print unsigned numbers
 * @n: number to print
 * Return: @count, number of chars printed.
 */
int print_unsig(unsigned int n)
{
	int check;
    int len;
    unsigned int num;

    check = 1;
    len = 0;

    num = n;

    for (; num / check > 9; )
        check *= 10;

    for (; check != 0; )
    {
        len += _putchar('0' + num / check);
        num %= check;
        check /= 10;
    }

    return (len);
}
/**
 * print_unsigned - Print unsigned decimal numbers.
 * @args: The variadic argument list.
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    return print_unsig(num);
}

