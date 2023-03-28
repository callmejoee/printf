#include "main.h"

int printchar(char c);
/**
 * print_num_helper- this function help print_num to print int;
 * @x: number
 * Return: retunr the length of int.
 */
int print_num_helper(int x)
{
	char c;
	int i;

	if (x == 0)
		return (0);
	i = 1 + print_num_helper(x / 10);
	c = x % 10 + '0';
	printchar(c);
	return (i);
}
/**
 * print_num - this function print number as a char;
 * @x: number
 * Return: return length of int.
 */
int print_num(int x)
{
	int length;

	if (x < 0)
	{
		printchar('-');
		length = print_num_helper(-x);
		return (length);
	}
	length = print_num_helper(x);
	return (length);
}
