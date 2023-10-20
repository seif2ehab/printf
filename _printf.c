#include "main.h"

/**
 * _printf - A function that produces output according to a format.
 * @format: the format string.
 * ...: the values to format and print.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list types;
    int i = 0, buff_ind = 0;
    char buffer[BUFF_SIZE] = {0};

    if (!format || (format[0] == '%' && format[1] == '\0'))
        return (-1);
    va_start(types, format);
    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            get_function(format[i + 1])(types, buffer, &buff_ind);
            i++;
        }
        else
        {
            buffer[buff_ind++] = format[i];
        }
        if (buff_ind == BUFF_SIZE)
            print_buffer(buffer, &buff_ind);
        i++;
    }
    va_end(types);
    if (buff_ind)
        print_buffer(buffer, &buff_ind);
    return (buff_ind);
}

/**
 * print_buffer - Prints the buffer content to stdout.
 * @buffer: the buffer to print.
 * @buff_ind: the pointer to the buffer index.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    write(1, buffer, *buff_ind);
    *buff_ind = 0;
}
