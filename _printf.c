#include "main.h"

/**
 * output_buffer - Outputs the buffer's content to the standard output.
 * @buf: Buffer containing characters.
 * @index: Current position in the buffer.
 */
void output_buffer(char *buf, int *index)
{
	if (*index > 0)
		write(1, buf, *index);

	*index = 0;
}

/**
 * custom_printf - A custom implementation of the printf function.
 * @pattern: The format string.
 *
 * Return: Number of characters printed.
 */
int custom_printf(const char *pattern, ...)
{
	int pos, char_count = 0, temp_count = 0;
	int formatting_flags, field_width, num_precision, specifier_size;
	int buffer_pos = 0;
	va_list args;
	char temp_buffer[BUFF_SIZE];

	if (!pattern)
		return (-1);

	va_start(args, pattern);

	for (pos = 0; pattern[pos]; pos++)
	{
		if (pattern[pos] != '%')
		{
			temp_buffer[buffer_pos++] = pattern[pos];
			if (buffer_pos == BUFF_SIZE)
				output_buffer(temp_buffer, &buffer_pos);
			char_count++;
		}
		else
		{
			output_buffer(temp_buffer, &buffer_pos);
			formatting_flags = fetch_flags(pattern, &pos);
			field_width = fetch_width(pattern, &pos, args);
			num_precision = fetch_precision(pattern, &pos, args);
			specifier_size = fetch_size(pattern, &pos);
			pos++;
			temp_count = manage_formatting(pattern, &pos, args, temp_buffer,
				formatting_flags, field_width, num_precision, specifier_size);
			if (temp_count == -1)
				return (-1);
			char_count += temp_count;
		}
	}

	output_buffer(temp_buffer, &buffer_pos);

	va_end(args);

	return (char_count);
}
