#include "main.h"

/**
 * main - test case
 *
 * Return: 0 (Success)
 *
 */

int main(void)
{
	int len;
	len = _printf("%c", 'm');
	printf(" <- letter m is printed and length is :%d\n", len);
	len = _printf("Character:[%c]\n number is ", 'H');
	printf("%d", len);
	return (0);
}
