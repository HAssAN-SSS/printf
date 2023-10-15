#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
char *plcType(const char *format, char *typePlc);
char **storArgs(va_list args, char **argArray, char *typePlc);
int stringHnadel(char **argArray, va_list args, int i);
int plcCounter(const char *format, int plcCount);







#endif
