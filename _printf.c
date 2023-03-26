#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - function that clone printf();
 * @format: format specifier
 * Return: length of sormat string
 */
int _printf(const char *format, ...)
{
	char *tmp;
	char *str, *new_string, c[1];
	int format_length, i, len, m;

	va_list vl;

	va_start(vl, format);

	tmp = (char *)format;
	if (tmp[0] == '%' && tmp != NULL)
	{
		if (tmp[1] == 's')
		{
			str = va_arg(vl, char*);
		}
		write(1, str, get_length(str));
	}
	for (m = 0; m < get_flag_number(tmp); m++)
	{
		format_length = get_length(tmp);
		while (i < format_length)
		{
			if (tmp[i] == '%')
			{
				if (tmp[i + 1] == 's')
				{
					str = va_arg(vl, char *);
					new_string = concatenat(tmp, 0, i, str);
					tmp = new_string;
				}
				else if (tmp[i + 1] == 'c')
				{
					c[0] = va_arg(vl, int);
					new_string = concatenat(tmp, 0, i, c);
					tmp = new_string;
				}
			}
			i++;
		}
	}
	va_end(vl);
	if (get_flag_number(tmp) == 0)
		new_string = (char *)format;
	len = write(1, new_string, get_length(new_string));
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
 * concatenat- function that concatenate two string
 * @s1: first string.
 * @start:input.
 * @end: input.
 * @s2: string two.
 * Return: the concatenate of two string.
 */
char *concatenat(char *s1, int start, int end, char *s2)
{
	int s2_length = get_length(s2);
	int s1_length = get_length(s1);
	int length = s1_length + s2_length;
	int i, j, k, n;
	char *new_string = malloc(length * sizeof(char) - 2);

	for (i = start; i < end; i++)
	{
		new_string[i] = s1[i];
	}
	n = i + 2;
	for (j = 0; j < s2_length; j++)
	{
		new_string[i++] = s2[j];
	}
	for (k = n; k < s1_length; k++)
	{
		new_string[i++] = s1[k];
	}
	return (new_string);
}
/**
 * get_flag_number - function that calculate number of flags in string
 * @s:input.
 * Return:numbe of flags.
 */
int get_flag_number(char *s)
{
	int number = 0;

	while (*s != '\0' && s != NULL)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c' || *s == 's')
				number++;
		}
		s++;
	}
	return (number);
}
