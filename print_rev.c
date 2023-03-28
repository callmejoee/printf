#include "main.h"

/**
 * print_rev - prints the reverse of the string
 *
 * @str: string
 *
 * Retrun: num of times function prints
 *
 */

int print_rev(char * str)
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
