<<<<<<< HEAD
#include <stdarg.h>
#include "main.h"

/**
 * _printf - this function print string and replace
 * %c with givent char to it .
 * @format : first function argum
 * @...:unlimited parameter
 * Return : length of format after replace flags with char.
=======
#include "main.h"

/**
 * _printf - function to be like printf
 *
 * @format: format specifier
 *
 * Return: length
>>>>>>> fde8c6e29b96cee31d405ce4b24c104012d631f6
 */

int _printf(const char *format, ...)
{
<<<<<<< HEAD
    int length = 0, i = 0;

    va_list args;
    va_start (args, format);

    /*while loop to loop over all fomrat string char by char
        we check if the first char is not null terminated char and format is not NULL
    */
    while (format[i] != '\0' && format != NULL)
    {
        if (format[i] == '%')
        {
            /*if we found % we need to check next char is 'c' or another char*/
            if (format[i+1] == 'c')
            {
                _putchar(va_arg(args, int));
                /*increase the length after printing the first char*/
                length++;
                /*increase i by 2 because i don't one to print the char after %*/
                i+=2;
            }
        }
        else
        {
            _putchar(format[i]);
            i++;
            length++;
        }

    }
    va_end(args);
    return (length);
}
=======
	int char_count = 0;
	int i = 0;
	char *str;
	int j = 0;
	va_list ptr;

	va_start(ptr, format);

	while (format[i] != '\0' && format != NULL)
	{
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
		else
		{
			++char_count;
			_putchar(format[i]);
		}
		i++;
	}

	return (char_count);
}
>>>>>>> fde8c6e29b96cee31d405ce4b24c104012d631f6
