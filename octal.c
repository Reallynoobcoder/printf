#include "main.h"

/**
 * print_oct - Print numbers in base 8 (octal).
 * @n: number to print
 * Return: @counter, number of chars printed.
 */
int print_oct(unsigned int n)
{
	unsigned int a, b, c, d, f;
	int counter = 0;

	b = n;
	c = 1;
	for (a = 1 ; b > 7 ; a++)
	{
		b = b / 8;
		c = c * 8;
		counter++;
	}
	for (f = 1; f <= a; f++)
	{
		d = n / c;
		n = n % c;
		c = c / 8;
		_putchar(d + '0');
		counter++;
	}
	return (counter);
}

/**
 * print_octal - Convert unsigned int to octal and print.
 *
 * @args: The va_list containing the unsigned int to be converted and printed.
 *
 * Return: The number of characters printed.
*/
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_oct(num));
}
