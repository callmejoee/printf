#include "main.h"

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
