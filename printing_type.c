#include "main.h"

/**
 * handle_print_type - Prints an argument based on its type
 * and shows it on the stdout
 * @frms: Formatted string in which to print
 * the arguments
 * @list: List of arguments to be printed
 * @edx: edx
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2
 */
int handle_print_type(const char *frms, int *edx, va_list list, char buffer[],
		 int flags, int width, int precision, int size)
{
	int a, unknwnlen = 0, printed_chars = -1;
	frms_t frms_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_module},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_upper_hexa}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	}

	for (a = 0; frms_types[i].frms != '\0'; a++)
	{
		if (frms[*edx] == frms_types[a].frms)
			return (frms_types[a].fn(list, buffer, flags, width, precision, size));
		if (frms_types[a].frms == '\0')
			return (-1);
		unknw_len += write(1, "%%", 1);
		if (frms[*edx - 1] == '')
			unknw_len += write(1, " ", 1);
		else if (width)
		{
			-(*edx);
			while (frms[*edx] != '' &&frms[*edx] != '%')
				-(*edx);
			if (frms[*edx] == '')
				-(*edx);
			return (1);
		}
		unknw_len += write(1, &frms[*edx], 1);
		return (unknw_len);
	}
	return (printed_chars);
}
