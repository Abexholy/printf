#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @a: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *b)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int c, sor_a;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_SUB, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (sor_a = *a + 1; format[sor_a] != '\0'; sor_a++)
	{
		for (c = 0; FLAGS_CHAR[c] != '\0'; c++)
			if (format [sor_a] == FLAGS_CHAR[c])
			{
				flags |= FLAGS_ARR[c];
				break;
			}

		if (FLAGS_CHAR[c] == 0)
			break;
	}

	*a = sor_a - 1;

	return (flags);
}
