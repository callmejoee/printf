#include "main.h"

int main(void)
{
	int num;
	num = _printf("%b\n", 2);
	printf("%d\n", num);
	num = _printf("%b\n", 022314);
        printf("%d\n", num);
	num = _printf("%b\n", 1555);
        printf("%d\n", num);
	num = _printf("%b\n", 95);
        printf("%d\n", num);
	num = _printf("%b\n", 5);
        printf("%d\n", num);
	num = _printf("%b\n", 12);
        printf("%d\n", num);
	num = _printf("%b\n", 442);
        printf("%d\n", num);
	num = _printf("%b\n", 0);
        printf("%d\n", num);
	return (0);
}
