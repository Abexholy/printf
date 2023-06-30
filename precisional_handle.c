#include "main.h"

/**
 * get_precision - Calculates the precision for
 * printing and returns the result to stdout
 * @format: Formatted string in which to print
 * the arguments
 * @a: List of arguments to be printed
 * @list: list of arguments
 *
 * Return: Precision
 */
int get_precision(const char *format, int *a, va_list list)
{
	int bur_a = *a + 1;
	int precision = -1;

	if (format[bur_a] != '.')
		return (precision);

	precision = 0;

	for (bur_a += 1; format[bur_a] != '\0'; bur_a++)
	{
		if (is_digit(format[bur_a]))
		{
			precision *= 10;
			precision += format[bur_a] - '0';
		}
		else if (format[bur_a] == '*')
		{
			bur_a++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = bur_a - 1;

	return (precision);
}
