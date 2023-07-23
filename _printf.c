#include "main.h"

typedef struct {
    char type;
    void (*print_function)(va_list);
} FormatSpecifier;

void print_char(va_list args) {
    char c = va_arg(args, int);
    putchar(c);
}

void print_string(va_list args) {
    const char *s = va_arg(args, const char*);
    for (int j = 0; s[j] != '\0'; j++) {
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
    {'\0', NULL}
};

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int len_count = 0;
    int i, j;

    for (i = 0; format[i] != '\0'; ++i) {
        if (format[i] != '%') {
            putchar(format[i]);
            len_count++;
        } else if (format[i] == '%') {
            i++;
            if (format[i] == '%') {
                putchar('%');
                len_count++;
            } else {
                for (j = sizeof(format_map) / sizeof(format_map[0]) - 1; j >= 0; --j) {
                    if (format[i] == format_map[j].type) {
                        format_map[j].print_function(args);
                        break;
                    }
                }
                if (format_map[j].type == '\0') {
                    print_unknown(args, format[i]);
                    len_count += 2;
                }
            }
        }
    }

    va_end(args);
    return len_count;
}
