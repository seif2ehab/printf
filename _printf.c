#include <stdio.h>
#include <stdarg.h>

/**
 * custom_printf - Custom implementation of printf.
 * @input_format: The format string.
 *
 * Return: Number of characters printed.
 */
int custom_printf(const char *input_format, ...);

/**
 * main - Main function to test custom_printf.
 *
 * Return: Always 0.
 */
int main(void)
{
    custom_printf("Hello, %corld! %s\n", 'W', "This is a test.");
    return (0);
}

/**
 * custom_printf - Custom implementation of printf.
 * @input_format: The format string.
 *
 * Return: Number of characters printed.
 */
int custom_printf(const char *input_format, ...)
{
    va_list arg_list;
    int chars_printed = 0;

    va_start(arg_list, input_format);
    while (*input_format)
    {
        if (*input_format == '%')
        {
            input_format++;
            switch (*input_format)
            {
                case 'c':
                    putchar(va_arg(arg_list, int));
                    chars_printed++;
                    break;
                case 's':
                {
                    char *str = va_arg(arg_list, char *);
                    while (*str)
                    {
                        putchar(*str);
                        chars_printed++;
                        str++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    chars_printed++;
                    break;
                default:
                    putchar('%');
                    putchar(*input_format);
                    chars_printed += 2;
                    break;
            }
        }
        else
        {
            putchar(*input_format);
            chars_printed++;
        }
        input_format++;
    }
    va_end(arg_list);
    return (chars_printed);
}
