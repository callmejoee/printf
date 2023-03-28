#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int printchar(char c);
int _printf(const char *format, ...);
int printstring(char *str);

/**
 * _printf - function that clone printf();
 * @format: format specifier
 * Return: length of sormat string
 */
int _printf(const char *format, ...)
{
	char *tmp;
	int len = 0, i = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (0);
	tmp = (char *)format;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '%')
		{
			if (tmp[i + 1] == 'c')
			{
				len += printchar(va_arg(arg, int));
				i += 2;
			}
			else if (tmp[i + 1] == 's')
			{
				len += printstring(va_arg(arg, char *));
				i += 2;
			}
			else if (tmp[i + 1] == '%')
			{
				len += printchar('%');
				i += 2;
			}
		}
		else
		{
			len += printchar(tmp[i]);
			i++;
		}
	}
	va_end(arg);
	return (len);
}
/**
 * printchar - function print c to stdou;
 * @c: character
 * Return: return 1 length of char.
 */
int printchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * printstring - function print string to stdou;
 * @str: string
 * Return: return length of str.
 */
int printstring(char *str)
{
	int len = 0, i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		len += printchar(str[i]);
		i++;
	}
	return (len);
}
