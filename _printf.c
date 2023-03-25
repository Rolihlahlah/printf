#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: pointer to string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int i, count = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				count += printf("%s", va_arg(args, char *));
				break;
			case '%':
				putchar('%');
				count++;
				break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}

	va_end(args);
	return (count);
}
