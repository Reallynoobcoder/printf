#include "main.h"
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
