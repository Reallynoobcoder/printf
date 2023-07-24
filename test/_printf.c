#include "main.h"

int parser(const char *format, conver_t funct_list[], va_list args)
{
    int i, j, r_val, printed_chars;

    printed_chars = 0;
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%') 
        {
            for (j = 0; funct_list[j].sym != NULL; j++)
            {
                if (format[i + 1] == funct_list[j].sym[0])
                {
                    r_val = funct_list[j].f(args);
                    if (r_val == -1)
                        return (-1);
                    printed_chars += r_val;
                    break;
                }
            }
            if (funct_list[j].sym == NULL && format[i + 1] != ' ')
            {
                if (format[i + 1] != '\0')
                {
                    _putchar(format[i]);
                    _putchar(format[i + 1]);
                    printed_chars = printed_chars + 2;
                }
                else
                    return (-1);
            }
            i = i + 1;
        }
        else
        {
            _putchar(format[i]);
            printed_chars++;
        }
    }
    return (printed_chars);
}
int _printf(const char *format, ...)
{
    int printed_chars;

    conver_t funct_list[] =    {
        {"c", p_char},
        {"s", p_string},
        {"%", p_percent},
        {NULL, NULL}
    };

    va_list args;


    if (format == NULL)
        return (-1);

    va_start(args, format);

    printed_chars = parser(format, funct_list, args);
    va_end(args);

    return (printed_chars);
}
