#include "main.h"
/**
 * process_format - This helper function processes the format string.
 *                  It iterates through the format string.
 *
 * @format: The format string containing text and conversion specifiers.
 * @formatMap: The list of conversion specifier mappings.
 * @size: The number of elements in the formatMap array.
 * @args: The variadic argument list.
 *
 * Return: The total number of characters printed on success, or -1 on failure.
 */

int process_format(const char *format,
		trans *formatMap, int size, va_list args)
{
	int i, j, rv;
	int len_count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; j < size; j++)
			{
				if (format[i + 1] == formatMap[j].spef[0])
				{
					rv = formatMap[j].f_ptr(args);
					if (rv == -1)
						return (-1);
					len_count = len_count + rv;
					break;
				}
			}
			if (j == size && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					len_count = len_count + 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			len_count++;
		}
	}
	return (len_count);
}

/**
 * _printf - This function processes the format string.
 *           It handles the conversion specifiers.
 *
 * @format: The format string containing text and conversion specifiers.
 * @...: The variadic arguments that match the conversion.
 *
 * Return: The total number of characters printed on success, or -1 on failure.
 */

int _printf(const char *format, ...)
{
	int len_count = 0;

	trans formatMap[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", print_unsigned}, {"o", print_octal},
		{"x", print_hex}, {"X", print_HEX},
		{"S", printf_S}, {"p", print_p},
		{"r", printf_reverse},
		{"R", printf_rot13}
	};
	int size = sizeof(formatMap) / sizeof(formatMap[0]);
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	len_count = process_format(format, formatMap, size, args);
	va_end(args);
	return (len_count);
}
