#include "main.h"

/**
 * get_function - Selects the correct function to perform the operation.
 * @c: Format specifier.
 * Return: Function pointer.
 */
int (*get_function(char c))(va_list, char *, int *)
{
    spec_t functions[] = {
        {"c", print_char},
        {"s", print_string},
        /* ... other format specifiers ... */
        {NULL, NULL}
    };
    int i = 0;

    while (functions[i].spec)
    {
        if (functions[i].spec[0] == c)
            return (functions[i].function);
        i++;
    }
    return (NULL);
}

/**
 * power - Calculates the power of a number.
 * @base: The base number.
 * @exp: The exponent.
 * Return: Result of the power operation.
 */
unsigned int power(int base, int exp)
{
    unsigned int result = 1;
    while (exp--)
    {
        result *= base;
    }
    return result;
}
