#include "main.h"

/**
 * print_p - Custom printf specifier function to print a pointer address.
 *
 * @args: The va_list containing the pointer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_p(va_list args)
{
	void *ptr = va_arg(args, void*);
	char buffer[40];
	int len_count = 0;

	if (ptr == NULL)
	{
		len_count = len_count + _printf("(nil)");
	}
	else
	{
		snprintf(buffer, sizeof(buffer), "%p", ptr);
		len_count = len_count + _printf("%s", buffer);
	}

	return (len_count);
}
