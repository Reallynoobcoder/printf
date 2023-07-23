#include "main.h"

typedef struct {
	char type;
	void (*print_function)(va_list);
} FormatSpecifier;

void print_char(va_list args) {
	char c = va_arg(args, int);
	putchar(c);
}

void print_string(va_list args)
{
	int j;
	const char *s = va_arg(args, const char*);
	for (j = 0; s[j] != '\0'; j++) {
		putchar(s[j]);
	}
}

void print_percent(va_list args) {
	(void)args;
	putchar('%');
}

void print_unknown(va_list args, int c) {
	(void)args;
	putchar('%');
	putchar(c);
}

FormatSpecifier format_map[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
};

int _printf(const char *format, ...) {
	va_list args;
	int len_count = 0;
	int i, j;

	va_start(args, format);
	
if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (i = 0; format[i] != '\0'; ++i) {
		if (format[i] != '%') {
			putchar(format[i]);
			len_count++;
		} else if (format[i] == '%') {
			i++;
			for (j = sizeof(format_map) / sizeof(format_map[0]); j > 0; --j)
			{
				if (format[i] == format_map[j].type) {
					format_map[j].print_function(args);
					len_count++;
					break;
				}
			}
			if (format_map[j].type == '\0') {
				print_unknown(args, format[i]);
				len_count = len_count + 2;
			}
		}
	}

	va_end(args);
	return len_count;
}
