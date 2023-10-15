#include "main.h"
/**
 * _printf - printf clone
 * @format: format
 * Return: count of printed chars
*/
int _printf(const char *format, ...)
{
int i = 0;
int k = 0;
int j = 0;
int finalCount = 0;

int plcCount = 0;
char *typePlc;
char **argArray;
va_list args;
va_start(args, format);

plcCount = plcCounter(format, plcCount);
printf("%s\n", format);
printf("count holders: %d\n", plcCount);
typePlc = malloc(sizeof(typePlc) * plcCount);
typePlc = plcType(format, typePlc);
argArray = malloc(sizeof(typePlc) * plcCount);
argArray = storArgs(args, argArray, typePlc);



while (format[i])
{

if (format[i] == '%' && format[i + 1] == '%')
{

write(1, &format[i + 1], 1);
finalCount++;

i++;
}
else
{
if (format[i] == '%' && format[i + 1] != '\0')
{
while (argArray[j][k])
{

write(1, &argArray[j][k], 1);
finalCount++;
k++;
}
j++;
i++;
i++;
}
else
{

write(1, &format[i], 1);
finalCount++;
i++;
}
}
k = 0;









}


for (i = 0; i < plcCount; i++)
{
free(argArray[i]);
}
free(argArray);

return (finalCount);
}


/**
 * plcCounter - give use info the text passed to the function.
 * @plcCount: the number of characters in the text.
 * @format: the indexes of the placeholders.
 * Return: coune '%'
*/
int plcCounter(const char *format, int plcCount)
{
int i = 0;
while (format[i] != '\0')
{
if (format[i] == '%' && format[i + 1] != '%')
{
{
plcCount++;
}
}
i++;
}
return (plcCount);
}


/**
 * plcType - replace the placeholders with the text passed to the function.
 * @format: nativ text.
 * @typePlc: pointer that contien deferent type that wase passed.
 * Return: the pointer.
*/
char *plcType(const char *format, char *typePlc)
{
int i = 0;
int k = 0;
while (format[i] != '\0')
{
if (format[i] == '%' && format[i + 1] != '%' && format[i + 1] != '\0')
{

typePlc[k] = format[i + 1];
printf("typePlc[%d]: %c\n", k, typePlc[k]);
k++;

}
i++;
}
return (typePlc);
}


/**
 * storArgs - prepare the place for the args.
 * @args: son los args.
 * @argArray: array of args.
 * @typePlc: pointer of type of args.
 * Return: array of pointers of args
*/
char **storArgs(va_list args, char **argArray, char *typePlc)
{
int i = 0;

while (typePlc[i])
{
switch (typePlc[i])
{
case 'c':
argArray[i] = malloc(sizeof(char));
if (argArray[i] == NULL)
{

break;
}
argArray[i][0] = (char)va_arg(args, int);

i++;
break;
case 's':
stringHnadel(argArray, args, i);
i++;

break;
case '%':

break;
default:
i++;
break;

}
}
return (argArray);
}







/**
 * stringHnadel - prepare the place for the args.
 * @argArray: array of args.
 * @args: the text passed to the function.
 * @i: the number of args.
 * Return: i
*/

int stringHnadel(char **argArray, va_list args, int i)
{
int j = 0;
char *stringo;
int strLen = 0;
stringo = va_arg(args, char *);
strLen = strlen(stringo);
argArray[i] = malloc(sizeof(char) * (strLen));
if (argArray[i] == NULL)
{
free(argArray);
return (-1);
}
while (stringo[j] != '\0')
{
argArray[i][j] = stringo[j];
j++;
}

return (0);
}
