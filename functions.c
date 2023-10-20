#include "main.h"

/**
 * write_spaces - Write spaces to standard output.
 * @space_count: The number of spaces to print.
 * Return: void.
 */
static void write_spaces(int space_count)
{
	for (int idx = 0; idx < space_count; idx++)
		write(1, " ", 1);
}

/**
 * print_char - Prints a char.
 * @arguments: Argument list.
 * @buf: Buffer.
 * @flag_value: Flags.
 * @width_value: Width.
 * @precision_value: Precision.
 * @size_value: Size.
 * Return: Number of chars printed.
 */
int print_char(va_list arguments, char buf[], int flag_value, int width_value,
	int precision_value, int size_value)
{
	char character_to_print = va_arg(arguments, int);

	return (handle_write_char(character_to_print, buf, flag_value, width_value, precision_value, size_value));
}

/**
 * print_string - Prints a string.
 * @arguments: Argument list.
 * @buf: Buffer.
 * @flag_value: Flags.
 * @width_value: Width.
 * @precision_value: Precision.
 * @size_value: Size.
 * Return: Number of chars printed.
 */
int print_string(va_list arguments, char buf[], int flag_value, int width_value,
	int precision_value, int size_value)
{
	char *string_to_print = va_arg(arguments, char *);
	int string_length = strlen(string_to_print);

	if (!string_to_print || (precision_value >= 0 && precision_value < 6))
		string_to_print = (precision_value >= 6) ? "      " : "(null)";

	string_length = (precision_value >= 0 && string_length > precision_value) ? precision_value : string_length;

	int spaces_needed = (width_value > string_length) ? width_value - string_length : 0;
	if (flag_value & F_MINUS)
	{
		write(1, string_to_print, string_length);
		write_spaces(spaces_needed);
	}
	else
	{
		write_spaces(spaces_needed);
		write(1, string_to_print, string_length);
	}
	return (string_length + spaces_needed);
}

/**
 * print_percent - Prints a percent sign.
 * @arguments: Argument list.
 * @buf: Buffer.
 * @flag_value: Flags.
 * @width_value: Width.
 * @precision_value: Precision.
 * @size_value: Size.
 * Return: Number of chars printed.
 */
int print_percent(va_list arguments, char buf[], int flag_value, int width_value,
	int precision_value, int size_value)
{
	UNUSED(arguments); UNUSED(buf); UNUSED(flag_value); UNUSED(width_value); UNUSED(precision_value); UNUSED(size_value);
	return (write(1, "%%", 1));
}

/**
 * print_int - Prints an integer.
 * @arguments: Argument list.
 * @buf: Buffer.
 * @flag_value: Flags.
 * @width_value: Width.
 * @precision_value: Precision.
 * @size_value: Size.
 * Return: Number of chars printed.
 */
int print_int(va_list arguments, char buf[], int flag_value, int width_value,
	int precision_value, int size_value)
{
	long int integer_value = va_arg(arguments, long int);

	/* Conversion and printing logic remains mostly the same... */

	return (/*...*/);
}

/**
 * print_binary - Prints a number in binary format.
 * @arguments: Argument list.
 * @buf: Buffer.
 * @flag_value: Flags.
 * @width_value: Width.
 * @precision_value: Precision.
 * @size_value: Size.
 * Return: Number of chars printed.
 */
int print_binary(va_list arguments, char buf[], int flag_value, int width_value,
	int precision_value, int size_value)
{
	unsigned int binary_value = va_arg(arguments, unsigned int);
	int bit_count = 0;

	if (binary_value == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	/* Binary conversion and printing logic... */

	return (bit_count);
}

