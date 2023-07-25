#include "main.h"

/**
 * print_hexaup - Convert unsigned int to hexadecimal and print in uppercase.
 *
 * @n: The unsigned int to be converted and printed.
 *
 * Return: The number of characters printed.
*/
int print_hexaup(unsigned int n)
{
	int i, j, rem, counter = 0;
	unsigned int num_copy = n;
	char *hex_ud;

	if (n == 0)
		return (_putchar('0'));

	for (counter = 0; num_copy != 0; counter++)
		num_copy /= 16;

	hex_ud = malloc(counter);
	for (i = 0; n != 0; i++)
	{
		rem = n % 16;
		hex_ud[i] = rem < 10 ? rem + '0' : rem + 'A' - 10;
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hex_ud[j]);

	free(hex_ud);
	return (counter);
}

/**
 * print_HEX - Convert unsigned int to hexadecimal and print in uppercase.
 *
 * @args: The va_list containing the unsigned int to be converted and printed.
 *
 * Return: The number of characters printed.
*/
int print_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hexaup(num));
}
