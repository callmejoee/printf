#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


void _putchar(char c);
int _printf(const char *format, ...);
int get_length(char *s);
char *replace(char *s1, int start, int end, char *s2);
int print_str(char *str);
int print_num(int num);
int print_bin(int num);

#endif
