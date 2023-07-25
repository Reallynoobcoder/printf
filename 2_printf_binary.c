#include "main.h"

int print_bi(unsigned int n)
{
	unsigned int a, b, c, d, f;
	int count = 0;

	b = n;
	c = 1;
	for (a = 1 ; b > 1 ; a++)
	{
		b = b / 2;
		c = c * 2;
	}
	for (f = 1; f <= a; f++)
	{
		d = n / c;
		n = n % c;
		c = c / 2;
		_putchar(d + '0');
		count++;
	}
	return (count);
}
int print_binary(va_list args) 
{
	unsigned int num = va_arg(args, unsigned int);
	return (print_bi(num));
}
