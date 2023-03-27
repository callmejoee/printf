#include "main.h"

/**
 * print_num - function to print num
 *
 * @num: number
 *
 * Return: number of integers printed
 *
 */

int print_num(int num)
{
	static int count = 0;
	if (num < 0)
	{
		++count;
		_putchar('-');
		num = -num;
	}
	if (num / 10)
		print_num(num / 10);

	++count;
	_putchar((num % 10) + '0');
	return (count);
}
