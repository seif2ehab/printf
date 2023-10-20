#include "main.h"

int print_unsigned(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	int buffer_index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);

	// ... rest of the code remains unchanged ...

	return (write_unsgnd(0, buffer_index, output_buffer, flags, width, precision, size));
}

int print_octal(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	int buffer_index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);

	// ... rest of the code remains unchanged ...

	return (write_unsgnd(0, buffer_index, output_buffer, flags, width, precision, size));
}

int print_hexadecimal(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args_list, "0123456789abcdef", output_buffer,
		flags, 'x', width, precision, size));
}

int print_hexa_upper(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args_list, "0123456789ABCDEF", output_buffer,
		flags, 'X', width, precision, size));
}

int print_hexa(va_list args_list, char map_to[], char output_buffer[],
	int flags, char flag_char, int width, int precision, int size)
{
	int buffer_index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);

	// ... rest of the code remains unchanged ...

	return (write_unsgnd(0, buffer_index, output_buffer, flags, width, precision, size));
}
