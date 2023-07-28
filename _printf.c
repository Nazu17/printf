#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf -  a function that produces output according to a format.
 * @format: format.
 * Return: printed chars.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	va_list args;
	va_start(args, format);

	int count = 0;
	for (int i = 0; format[i] != '\0'; i++)
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

					{
						char *str = va_arg(args, char *);
						
						for (int j = 0; str[j] != '\0'; j++)
						{
							putchar(str[j]);
							count++;
						}
						break;
					}
				case '%':
					putchar('%');
					count++;
					break;
				default:
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
	return count;
}
