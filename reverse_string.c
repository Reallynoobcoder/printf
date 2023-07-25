#include "main.h"
int printf_reverse(va_list args)
{
	char *str = va_arg(args, char*);
	int i = 0;
	int str_len = 0;

	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		_putchar(str[i]);
		str_len++;
		i--;
	}
	return (str_len);
}
