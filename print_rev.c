#include "main.h"
/**
 * print_rev- this function reverse given string.
 * @str: input number of parameter.
 * Return: the length of str.
 */

int print_rev(char *str)
{
	int len, i = 0, count = 0;

	if (str == NULL)
		return (-1);
	len = strlen(str) - 1;

	while (str[i] != '\0')
	{
		++count;
		printchar(str[len - i]);
		i++;
	}
	return (count);
}
