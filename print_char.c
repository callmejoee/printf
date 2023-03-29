#include "main.h"
/**
 * printchar - function print c to stdou;
 * @c: character
 * Return: return 1 length of char.
 */
int printchar(char c)
{
	return (write(1, &c, 1));
}
