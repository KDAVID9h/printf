#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string to check for width specifier
 * @i: Pointer to the current index in the format string
 * @list: List of arguments
 *
 * Return: Width specifier or 0 if none
 */
int get_width(const char *format, int *i, va_list list)
{
	int currIndex;
	int width = 0;

	for (currIndex = *i + 1; format[currIndex] != '\0'; currIndex++)
	{
		if (is_digit(format[currIndex]))
		{
			width *= 10;
			width += format[currIndex] - '0';
		}
		else if (format[currIndex] == '*')
		{
			currIndex++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currIndex - 1;

	return (width);
}
