#include "main.h"

/**
 * print_number - Print an integer.
 *
 * Conversion specifier function for '%d'.
 * Prints the integer from va_list using _putchar.
 *
 * @args: The va_list containing the integer to be printed.
 *
 * Return: Number of characters printed.
 */

int print_number(va_list args)
{
	int n = va_arg(args, int);
	int check = 1;
	int len_count = 0;
	unsigned int num = (n < 0) ? -n : n;

	if (n < 0)
	{
		len_count += _putchar('-');
	}

	while (num / check > 9)
		check *= 10;


	while (check != 0)
	{
		len_count += _putchar(num / check + '0');
		num %= check;
		check /= 10;
	}

	return (len_count);
}


/**
 * print_integer - Print an integer from variadic arguments.
 *
 * Conversion specifier function for '%i'.
 * Calls print_number to print the integer
 * and returns the number of characters printed.
 *
 * @args: The va_list containing the integer argument to be printed.
 *
 * Return: Number of characters printed by print_number.
 */

int print_integer(va_list args)
{
	int num;

	num = print_number(args);
	return (num);

}
