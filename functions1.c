#include "main.h"

/**
 * print_unsigned - Print an unsigned number.
 * @arg_list: Argument list.
 * @buf: Buffer array for printing.
 * @print_flags: Flags for printing format.
 * @print_width: Specified width.
 * @print_precision: Specified precision.
 * @print_size: Specified size.
 * Return: Number of characters printed.
 */
int print_unsigned(va_list arg_list, char buf[],
	int print_flags, int print_width, int print_precision, int print_size)
{
	int buffer_idx = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arg_list, unsigned long int);

	number = convert_size_unsgnd(number, print_size);
	if (number == 0)
		buf[buffer_idx--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buf[buffer_idx--] = (number % 10) + '0';
		number /= 10;
	}
	buffer_idx++;

	return (write_unsgnd(0, buffer_idx, buf, print_flags, print_width, print_precision, print_size));
}

/**
 * print_octal - Print an unsigned number in octal format.
 * @arg_list: Argument list.
 * @buf: Buffer array for printing.
 * @print_flags: Flags for printing format.
 * @print_width: Specified width.
 * @print_precision: Specified precision.
 * @print_size: Specified size.
 * Return: Number of characters printed.
 */
int print_octal(va_list arg_list, char buf[],
	int print_flags, int print_width, int print_precision, int print_size)
{
	int buffer_idx = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arg_list, unsigned long int), original_number = number;

	UNUSED(print_width);
	number = convert_size_unsgnd(number, print_size);
	if (number == 0)
		buf[buffer_idx--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buf[buffer_idx--] = (number % 8) + '0';
		number /= 8;
	}

	if (print_flags & F_HASH && original_number != 0)
		buf[buffer_idx--] = '0';
	buffer_idx++;

	return (write_unsgnd(0, buffer_idx, buf, print_flags, print_width, print_precision, print_size));
}

// ... (remaining functions follow a similar naming convention)


