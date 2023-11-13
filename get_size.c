#include "main.h"

/**
 * get_size - Determines the size to cast the argument
 * @format: Formatted string to check for size specifier
 * @i: Pointer to the current index in the format string
 *
 * Return: Size specifier (S_LONG, S_SHORT) or 0 if none
 */
int get_size(const char *format, int *i)
{
	int currIndex = *i + 1;
	int size = 0;

	switch (format[currIndex])
	{
	case 'l':
		size = S_LONG;
		break;
	case 'h':
		size = S_SHORT;
		break;
	default:
		*i = currIndex - 1;
	}

	*i = (size == 0) ? currIndex - 1 : currIndex;
	return (size);
}
