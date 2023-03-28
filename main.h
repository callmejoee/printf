#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


int _printf(const char *format, ...);
int printstring(char *str);
int printchar(char c);

int print_num(int num);
int print_bin(int num);
int print_rev(char *str);

#endif
