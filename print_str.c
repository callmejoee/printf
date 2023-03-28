#include "main.h"

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
