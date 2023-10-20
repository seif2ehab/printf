#include "main.h"

int print_char(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	char character = va_arg(args_list, int);
	return (handle_write_char(character, output_buffer, flags, width, precision, size));
}

int print_string(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	int string_length = 0, index;
	char *input_string = va_arg(args_list, char *);

	// ... rest of the code remains unchanged ...

	return (write(1, input_string, string_length));
}

int print_percent(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args_list);
	UNUSED(output_buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

int print_int(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	int buffer_index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int number = va_arg(args_list, long int);
	unsigned long int absolute_number;

	// ... rest of the code remains unchanged ...

	return (write_number(is_negative, buffer_index, output_buffer, flags, width, precision, size));
}

int print_binary(va_list args_list, char output_buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int number, temp_num, index, sum;
	unsigned int binary_array[32];
	int count;

	// ... rest of the code remains unchanged ...

	return (count);
}
