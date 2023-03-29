#include "main.h"

/**
 * print_bin - function that takes number and converts it to binary
 *
 * @num: number in decimal
 *
 * Return: count of printed num
 *
 */

int print_bin(unsigned int num)
{
	int i = 0, j = 0, count = 0, bin_array[32];

	if (num == 0)
	{
		++count;
		printchar('0');
	}
	while (num > 0)
	{
		bin_array[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		++count;
		printchar(bin_array[j] + '0');
	}

	return (count - 1);
}
