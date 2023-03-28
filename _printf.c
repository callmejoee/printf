#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int printchar(char c);
int _printf(const char *format, ...);
int printstring(char *str);
int print_num(int x);
int print_bin(int num);
int print_rev(char *);

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
			else if (tmp[i + 1] == 'd' || tmp[i + 1] == 'i')
			{
				len += print_num(va_arg(arg, int));
				i += 2;
			}
			else if (tmp[i + 1] == 'b')
			{
				len += print_bin(va_arg(arg, int));
				i += 2;
			}
			else if (tmp[i + 1] == 'r')
                        {
                                len += print_rev(va_arg(arg, char *));
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
/**
 * printchar - function print c to stdou;
 * @c: character
 * Return: return 1 length of char.
 */

int printchar(char c)
{
	return (write(1, &c, 1));
}
int printchar(char c);
/**
 * print_num_helper- this function help print_num to print int;
 * @x: number
 * Return: retunr the length of int.
 */
int print_num_helper(int x)
{
	char c;
	int i;

	if (x == 0)
		return (0);
	i = 1 + print_num_helper(x / 10);
	c = x % 10 + '0';
	printchar(c);
	return (i);
}
/**
 * print_num - this function print number as a char;
 * @x: number
 * Return: return length of int.
 */
int print_num(int x)
{
	int length;

	if (x == 0)
	{
		printchar('0');
		return (1);
	}
	if (x < 0)
	{
		printchar('-');
		length = 1 + print_num_helper(-x);
		return (length);
	}
	length = print_num_helper(x);
	return (length);
}
/**
 * print_bin - function that takes number and converts it to binary
 *
 * @num: number in decimal
 *
 * Return: count of printed num
 *
 */

int print_bin(int num)
{
	int i = 0, j = 0, count = 0, bin_array[32];

	if (num == 0)
	{
		++count;
		printchar('0');
	}
	while (num > 0)
	{
		bin_array[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		++count;
		printchar(bin_array[j] + '0');
	}

	return (count - 1);
}


