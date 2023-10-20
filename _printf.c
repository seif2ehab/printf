#include "main.h"

void print_buffer(char output_buffer[], int *output_buffer_index);

int _printf(const char *format_string, ...)
{
	int index, total_chars_printed = 0, chars_printed = 0, output_buffer_index = 0;
	int flags, width, precision, size;
	va_list args_list;
	char output_buffer[BUFF_SIZE];

	if (format_string == NULL)
		return (-1);

	va_start(args_list, format_string);

	for (index = 0; format_string && format_string[index] != '\0'; index++)
	{
		if (format_string[index] != '%')
		{
			output_buffer[output_buffer_index++] = format_string[index];
			if (output_buffer_index == BUFF_SIZE)
				print_buffer(output_buffer, &output_buffer_index);
			total_chars_printed++;
		}
		else
		{
			print_buffer(output_buffer, &output_buffer_index);
			flags = get_flags(format_string, &index);
			width = get_width(format_string, &index, args_list);
			precision = get_precision(format_string, &index, args_list);
			size = get_size(format_string, &index);
			++index;
			chars_printed = handle_print(format_string, &index, args_list, output_buffer,
				flags, width, precision, size);
			if (chars_printed == -1)
				return (-1);
			total_chars_printed += chars_printed;
		}
	}

	print_buffer(output_buffer, &output_buffer_index);

	va_end(args_list);

	return (total_chars_printed);
}

void print_buffer(char output_buffer[], int *output_buffer_index)
{
	if (*output_buffer_index > 0)
		write(1, &output_buffer[0], *output_buffer_index);

	*output_buffer_index = 0;
}
