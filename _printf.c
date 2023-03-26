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
	va_list ptr;

	va_start(ptr, format);
	
	/* while the string entered is not end of string or null */
	while (format[i] != '\0' && format != NULL)
	{
		/* if the char pointed to now is % then see the char after it */
		if (format[i] == '%')
		{
			++i;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(ptr, int));
			}
		}
		/* if it is not a special char print it and increase count */
		else
		{
			_putchar(format[i]);
			char_count++;
		}
		i++;
	}

	return (char_count);
}
