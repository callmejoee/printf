#include "main.h"

/**
 * print_rot - prints
 *
 * @str: string
 *
 * Return: int
 */

int print_rot(char *str)
{
	int i = 0, count = 0;
	int def_val;

	while (str[i] != '\0')
        {
		while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{

                        def_val = 13;
                        if ((str[i] > 'm' && str[i] <= 'z') || (str[i] > 'M' && str[i] <= 'Z'))
                                def_val = -13;
                        str[i] += def_val;
			write(1, &str[i], 1);
			count++;
                        break;
                }
		if (isspace(str[i]) || ispunct(str[i]))
                {
                    write(1, &str[i], 1);
                    count++;
                }
                i++;
	}
	return (count);
}
