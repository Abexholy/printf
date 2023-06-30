#include "main.h"
#include <stdarg.h>
#include <stdio.h>

void print_buffer(char buffer[], int *buff_idx);

/**
 * _printf - Printf functions
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int c, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_idx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (c = 0; format && format[c] != '\0'; i++)
	{
		if (format[c] != '%')
		{
			buffer[buff_idx++] = format[c];
			if (buff_idx == BUFF_SIZE)
				print_buffer(buffer, &buff_idx);
			/** write(1, &format[c], 1); **/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_idx);
			flags = get_flags(format, &c);
			width = get_width(format, &c, list);
			precision = get_precision(format, &c, list);
			size = get_size(format, &c);
			++c;
			printed = handle_print(format, &c, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_idx);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_idx: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_idx)
{
	if (*buff_idx > 0)
		write(1, &buffer[0], *buff_idx);

	*buff_idx = 0;
}

