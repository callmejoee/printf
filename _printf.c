#include "main.h"

/**
 * _printf - function to be like printf
 *
 * @format: format specifier
 *
 * Return: length
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	int i = 0;
	int num;
	char *str;
	va_list ptr;

	va_start(ptr, format);

	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			++i;
			while (format[i] == ' ')
				++i;
			switch (format[i])
			{
				case 'c':
					++char_count;
					_putchar(va_arg(ptr, int));
					break;
				case 's':
					str = va_arg(ptr, char *);
					char_count += print_str(str);
					break;
				case 'i':
				case 'd':
					num = va_arg(ptr, int);
					char_count += print_num(num);
					break;
				default:
					continue;
			}
		}
		else
		{
			++char_count;
			_putchar(format[i]);
		}
		i++;
	}

	return (char_count);
}
