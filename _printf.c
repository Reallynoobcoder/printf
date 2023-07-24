#include "main.h"
/**
 * process_format - This helper function processes the format string.
 *                  It iterates through the format string.
 *
 * @format: The format string containing text and conversion specifiers.
 * @funct_list: The list of conversion specifier mappings.
 * @size: The number of elements in the funct_list array.
 * @args: The variadic argument list.
 *
 * Return: The total number of characters printed on success, or -1 on failure.
 */

int process_format(const char *format,
		conver_t *funct_list, int size, va_list args)
{
	int i, j, r_val;
	int result = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; j < size; j++)
			{
				if (format[i + 1] == funct_list[j].sym[0])
				{
					r_val = funct_list[j].f(args);
					if (r_val == -1)
						return (-1);
					result += r_val;
					break;
				}
			}
			if (funct_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					result += 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			result++;
		}
	}
	return (result);
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
	int result = 0;

	conver_t funct_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer}
	};
	int size = sizeof(funct_list) / sizeof(funct_list[0]);
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	result = process_format(format, funct_list, size, args);
	va_end(args);
	return (result);
}
