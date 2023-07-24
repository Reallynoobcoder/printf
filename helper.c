#include "main.h"

/**
 * print_char - Print character from variadic arguments.
 *
 * This function is a conversion specifier function for '%c'.
 * It prints the next argument from the va_list as a character.
 *
 * @args: The va_list containing the argument to be printed.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - Print a string from variadic arguments.
 *
 * This function is a conversion specifier for '%s'.
 * It prints the next argument as a string using _putchar.
 *
 * @args: The va_list containing the argument to be printed.
 *
 * Return: The number of characters printed.
 */

int print_string(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - Print a '%' character.
 *
 * This function is a conversion specifier function for '%%'.
 * It prints the '%' character using _putchar and returns 1.
 *
 * @args: The va_list (unused in this function).
 *
 * Return: Always returns 1 (number of characters printed).
 */

int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
