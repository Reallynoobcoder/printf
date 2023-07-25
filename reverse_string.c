#include "main.h"

/**
 * printf_reverse - Custom printf function to print a string in reverse.
 *
 * @args: The va_list containing the string to be printed in reverse.
 *
 * Return: The number of characters printed.
*/

int printf_reverse(va_list args)
{
	char *str = va_arg(args, char*);
	int i = 0;
	int len_str = 0;

	while (str[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		_putchar(str[i]);
		len_str++;
		i--;
	}
	return (len_str);
}
