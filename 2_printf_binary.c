#include "main.h"

/**
 * print_bi - Prints the binary representation of an unsigned integer.
 *
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_bi(unsigned int n)
{
	unsigned int a, b, c, d, i;
	int count = 0;

	b = n;
	c = 1;
	for (a = 1 ; b > 1 ; a++)
	{
		b = b / 2;
		c = c * 2;
	}
	for (i = 1; i <= a; i++)
	{
		d = n / c;
		n = n % c;
		c = c / 2;
		_putchar(d + '0');
		count++;
	}
	return (count);
}

/**
 * print_binary - Prints the binary representation of an unsigned integer.
 *
 * @args: The va_list containing the unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_bi(num));
}
