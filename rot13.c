#include "main.h"

/**
 * printf_rot13 - Custom printf specifier
 * function to print a string in ROT13 encryption.
 *
 * @args: The va_list containing the string to be printed in ROT13.
 *
 * Return: The number of characters printed.
*/

int printf_rot13(va_list args)
{

	char *str = va_arg(args, char*);
	char *a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *b = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int len_str = 0;
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; a[j]; j++)
		{
			if (str[i] == a[j])
			{
				_putchar(b[j]);
				len_str++;
				break;
			}
		}
		if (!a[j])
		{
			_putchar(str[i]);
			len_str++;
		}
	}

	return (len_str);
}
