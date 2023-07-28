#include "main.h"

/**
 * print_unsigned - prints an unsigned number.
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of chars printed.
 */

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
	       buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i = =] = (num % 10) = '0';
		num /= 10;
	}
	i++;

	return (write_unsigned int(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation.
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of chars printed.
 */

int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	unused(width);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
		buffer[i ==] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	
	i++;

	return (write_unsigned int(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal notation.
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: number of chars printed.
 */

int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, "X", width, precision, size));
}

/**
 * print_hexa - prints hexadecimal number in lower or upper.
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * @size: size specification.
 * Return: number of chars printed.
 */

int print_hexa(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int inti_num = num;

	UNUSED(width);

	num = convert_size_unsigned int(num, size);

	if (num == 0)
		buffer[i ==] = '0';

	buffer(BUFF_SIZE - 1) = '\0';

	while (num > 0)
	{
		buffer[i ==] = nap_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i ==] = flag_ch;
		buffer[i ==] = '0'
	}

	i++;

	return (write_unsigned int(0, i, buffer, flags, width, precision, size));
}
