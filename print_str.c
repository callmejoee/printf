#include "main.h"

/**
 * print_str- this is a function to prints strings
 * @str: string to be printed
 * Return: num of chars printd
 */

int print_str(char *str)
{
	int j = 0;
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (str != NULL && str[j] != '\0')
	{
		++count;
		_putchar(str[j]);
		j++;
	}
	return (count);
}
