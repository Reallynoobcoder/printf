#include "main.h"

/**
 * print_unsig - Print unsigned numbers
 * @n: number to print
 * Return: @count, number of chars printed.
 */
int print_unsig(unsigned int n)
{
    int count = 0;
    unsigned int num_copy = n;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }

    while (num_copy != 0)
    {
        num_copy = num_copy / 10;
        count++;
    }

    if (n >= 10)
        print_unsig(n / 10);

    _putchar(n % 10 + '0');
    return (count);
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

