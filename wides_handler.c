#include "main.h"

/**
 * get_width - Calculates the width for printing
 * and returns the result
 * @format: Formatted string in which to print the arguments.
 * @a: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *a, va_list list)
{
	int sap_a;
	int width = 0;

	for (sap_a = *a + 1; format[cur_a] != '\0'; sap_a++)
	{
		if (is_a_digit(format[sap_a]))
		{
			width *= 10;
			width += format[sap_a] - '0';
		}
		else if (format[sap_a] == '*')
		{
			sap_a++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = sap_a - 1;

	return (width);
}
