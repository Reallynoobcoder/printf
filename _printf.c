#include "main.h"

int process_format(const char *format, conver_t *funct_list, int size, va_list args)
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
                        return -1;
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
                {
                    return -1;
                }
            }
            i = i + 1;
        }
        else
        {
            _putchar(format[i]);
            result++;
        }
    }

    return result;
}

int _printf(const char *format, ...)
{
    int result = 0;

    conver_t funct_list[] = {
        {"c", p_char},
        {"s", p_string},
        {"%", p_percent},
    };
    int size = sizeof(funct_list) / sizeof(funct_list[0]);

    va_list args;
    va_start(args, format);

    if (format == NULL)
    {
        va_end(args);
        return -1;
    }

    result = process_format(format, funct_list, size, args);

    va_end(args);
    return result;
}

