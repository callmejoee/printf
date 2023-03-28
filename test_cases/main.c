#include "../main.h"


int main(void)
{
	int len;
	char *str = "My name is";
	len = _printf("%s\n", str);
	printf("%d\n", len);
	len = _printf("%r\n", str);
        printf("%d\n", len);
	return (0);
}
