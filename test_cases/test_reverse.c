#include "../main.h"

int main(void)
{
       	// Test case 1: simple string
    char str1[] = "hello";
    printf("Test case 1:\nInput: \"%s\"\nExpected output: \"olleh\"\n", str1);
    _printf("%r", str1);
    printf("\n\n");

    // Test case 2: empty string
    char str2[] = "";
    printf("Test case 2:\nInput: \"%s\"\nExpected output: \"\"\n", str2);
    _printf("%r", str2);
    printf("\n\n");

    // Test case 3: string with one character
    char str3[] = "a";
    printf("Test case 3:\nInput: \"%s\"\nExpected output: \"a\"\n", str3);
    _printf("%r", str3);
    printf("\n\n");

    // Test case 4: string with special characters
    char str4[] = "Hello, world!";
    printf("Test case 4:\nInput: \"%s\"\nExpected output: \"!dlrow ,olleH\"\n", str4);
    _printf("%r", str4);
    printf("\n\n");

	return(0);
}
