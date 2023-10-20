#include "main.h"

// Function to output the buffer's content
void output_buffer_content(char buf[], int *buf_idx);

/**
 * custom_printf - A custom implementation of printf.
 * @fmt: The format string.
 * 
 * Return: Number of characters printed.
 */
int custom_printf(const char *fmt, ...)
{
	int i, result = 0, total_chars = 0;
	int flag_vals, width_val, prec_val, type_val, buf_idx = 0;
	va_list args_list;
	char buf[BUFF_SIZE];

	// Check if the format string is not provided
	if (!fmt)
		return (-1);

	va_start(args_list, fmt);

	for (i = 0; fmt && fmt[i] != '\0'; i++)
	{
		// If current character is not a placeholder
		if (fmt[i] != '%')
		{
			buf[buf_idx++] = fmt[i];
			if (buf_idx == BUFF_SIZE)
				output_buffer_content(buf, &buf_idx);
			total_chars++;
		}
		else
		{
			// Process the buffer content
			output_buffer_content(buf, &buf_idx);

			// Get formatting information
			flag_vals = get_flag_values(fmt, &i);
			width_val = get_width_value(fmt, &i, args_list);
			prec_val = get_precision_value(fmt, &i, args_list);
			type_val = get_type_value(fmt, &i);
			i++;

			// Print according to the format
			result = format_handler(fmt, &i, args_list, buf,
				flag_vals, width_val, prec_val, type_val);
			if (result == -1)
				return (-1);

			total_chars += result;
		}
	}

	// Empty any remaining content in the buffer
	output_buffer_content(buf, &buf_idx);

	va_end(args_list);

	return (total_chars);
}

/**
 * output_buffer_content - Outputs the buffer's current content.
 * @buf: Buffer containing characters.
 * @buf_idx: Index representing buffer's length.
 */
void output_buffer_content(char buf[], int *buf_idx)
{
	if (*buf_idx > 0)
		write(1, buf, *buf_idx);

	*buf_idx = 0;
}
