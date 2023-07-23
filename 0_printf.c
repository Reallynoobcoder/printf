#include "main.h"
/**
 * _printf - Prints a formatted string
 * @format: A string containing all the desired characters
 *
 * Return: The total count of the characters printed
 */

typedef struct
{
	char type;
	char c;
	const char *s;
} FormatSpecifier;

	int _printf(const char *format, ...)
{
	va_list args;

	int chars_printed = 0;
	int i, j;
	FormatSpecifier fs;
	va_start (args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar (format[i]);
			chars_printed++;
		}
		else if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
			{
				fs.c = (char) va_arg (args, int);
				putchar (fs.c);
				chars_printed++;
			}
			else if (format[i] == 's')
			{
				fs.s = va_arg (args, const char *);
				for (j = 0; fs.s[j] != '\0'; j++)
				{
					putchar (fs.s[j]);
					chars_printed++;
				}
			}

			else if (format[i] == '%')
			{
				putchar ('%');
				chars_printed++;
			}
			else if (format[i] != '%')
			{
				putchar ('%');
				putchar (format[i - 1]);
				chars_printed += 2;
			}
		}
	}
	va_end (args);
	return (chars_printed);
}
