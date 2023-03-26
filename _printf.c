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
	/* string to hold the input string temp
	 * until it is printed */
	char *str;
	int j = 0;
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
					break;
				case 's':
					str = va_arg(ptr, char *);
					while (str != NULL && str[j] != '\0')
					{
						++char_count;
						_putchar(str[i]);
						j++;
					}
					break;
				
			}
		}
		/* if it is not a special char print it and increase count */
		else
		{
			++char_count;
			_putchar(format[i]);
		}
		i++;
	}

	return (char_count);
}
