#include "main.h"

int print_single_hex(char c)
{
	int len_count = 0;
	char hex_digits[] = "0123456789ABCDEF";
	char hex_represent[2];

	hex_represent[0] = hex_digits[c >> 4];
	hex_represent[1] = hex_digits[c & 0x0F];

	_putchar('\\');
	_putchar('x');
	_putchar(hex_represent[0]);
	_putchar(hex_represent[1]);

	len_count += 4;

	return (len_count);
}
int printf_S(va_list args)
{
	const char *str = va_arg(args, const char *);
	int num = 0, i;

	if (str == NULL)
		str = "(null)";

for (i = 0; str[i]; i++)
{
    if (str[i] < 32 || str[i] >= 127)
    {
        num += print_single_hex(str[i]);
    }
    else
    {
        _putchar(str[i]);
        num++;
    }
}

	return (num);
}
