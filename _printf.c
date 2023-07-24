#include "main.h"

int _printf(const char *format, ...)
{
    int i, j, r_val;
    int result = 0;

    conver_t funct_list[] = {
        {"c", p_char},
        {"s", p_string},
        {"%", p_percent},
        
    };
int size = (sizeof(funct_list) / sizeof(funct_list[0]));
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

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
                    {
                        va_end(args);
                        return (-1);
                    }
                    result += r_val;
                    break;
                }
            }
            if (size == j && format[i + 1] != ' ')
            {
                if (format[i + 1] != '\0')
                {
                    _putchar(format[i]);
                    _putchar(format[i + 1]);
                    result += 2;
                }
                else
                {
                    va_end(args);
                    return (-1);
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

    va_end(args);
    return result;
}
