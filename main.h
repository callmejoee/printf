#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

void _putchar(char c);
int _printf(const char *format, ...);

int print_num(int x);
int printchar(char c);
int printstring(char *str);

int print_str(char *str);
int print_num(int num);
int print_bin(int num);

#endif
