#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - function that clone printf();
 * @format: format specifier
 * Return: length of sormat string
 */
int _printf(const char *format, ...)
{
	char *tmp;
	char c[1], str[10];
	int i = 0, len, flag;
	va_list vl;

	if (format == NULL)
		return (0);
	va_start(vl, format);
	tmp = (char *)format;

	while (tmp != NULL && tmp[i] != '\0')
	{
		if (tmp[i] == '%')
		{
			flag++;
			if (tmp[i + 1] == 's')
				tmp = replace(tmp, i, i + 2, va_arg(vl, char *));
			else if (tmp[i + 1] == '%')
				tmp = replace(tmp, i, i + 2, "%");
			else if (tmp[i + 1] == 'c')
			{
				c[0] = va_arg(vl, int);
				tmp = replace(tmp, i, i + 2, c);
			}
			else if (tmp[i + 1] == 'd' || tmp[i + 1] == 'i')
			{
				sprintf(str, "%d", va_arg(vl, int));
				tmp = replace(tmp, i, i + 2, str);
			}
		}
		i++;
	}
	va_end(vl);
	if (tmp != NULL)
		len = write(1, tmp, get_length(tmp));
	if (flag != 0)
		free(tmp);
	if (tmp == NULL)
		return (0);
	return (len);
}

/**
 * get_length- functio got get the length of a string;
 * @s: string
 * Return: length of a string
 */
int get_length(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	s -= length;
	return (length);
}
/**
 * replace- function that concatenate two string
 * @s1: first string.
 * @start:input.
 * @end: input.
 * @s2: string two.
 * Return: the concatenate of two string.
 */
char *replace(char *s1, int start, int end, char *s2)
{
	int s2_length, s1_length, length, i, j, k;
	char *new_string;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s2_length = get_length(s2);
	s1_length = get_length(s1);
	length = s1_length + s2_length;
	new_string = malloc(length * sizeof(char) - 2);

	if (s1 == NULL || s2 == NULL)
		return (NULL);

	for (i = 0; i < start; i++)
	{
		new_string[i] = s1[i];
	}

	for (j = 0; j < s2_length; j++)
	{
		new_string[i++] = s2[j];
	}
	for (k = end; k < s1_length; k++)
	{
		new_string[i++] = s1[k];
	}
	return (new_string);
}
