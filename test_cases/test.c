#include "main.h"

/**
 * main - test case
 *
 * Return: 0 (Success)
 *
 */

int main(void)
{
	int len, len2;
	
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
   	printf("Character:[%c]\n", 'H');
	printf("Length 1 comes to 39 and is : %d\n and length two is %d\n", len, len2);


	return (0);
}
