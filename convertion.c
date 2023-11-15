#include "main.h"

/**
 * print_hexa - prints unsigned hexadecimal numbers in lowercase
 * @a: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_hexa(va_list a, params_t *params)
{
	unsigned long lo;
	int i = 0;
	char *s;

	if (params->modifier_l)
	{
		lo = (unsigned long)va_arg(a, unsigned long);
	}
	else if (params->modifier_h)
	{
		lo = (unsigned long int)va_arg(a, unsigned int);
	}
	else
	{
		lo = (unsigned int)va_arg(a, unsigned int);
	}

	s = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag && lo)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsigne = 1;
	return (i += print_number(s, params));
}

/**
 * print_HEXA - prints unsigned hexadecimal numbers in uppercase
 * @a: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_HEXA(va_list a, params_t *params)
{
	unsigned long lo;
	int i = 0;
	char *s;

	if (params->modifier_l)
	{
		lo = (unsigned long)va_arg(a, unsigned long);
	}
	else if (params->modifier_h)
	{
		lo = (unsigned long int)va_arg(a, unsigned int);
	}
	else
	{
		lo = (unsigned int)va_arg(a, unsigned int);
	}

	s = convert(lo, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag && lo)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsigne = 1;
	return (i += print_number(s, params));
}

/**
 * print_binary - prints unsigned binary numbers
 * @a: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_binary(va_list a, params_t *params)
{
	unsigned int n = va_arg(a, unsigned int);
	char *s = convert(n, 2, CONVERT_UNSIGNED, params);
	int i = 0;

	if (params->hashtag && n)
		*--s = '0';
	params->unsigne = 1;
	return (i += print_number(s, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @a: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_octal(va_list a, params_t *params)
{
	unsigned long lo;
	int i = 0;
	char *s;

	if (params->modifier_l)
	{
		lo = (unsigned long)va_arg(a, unsigned long);
	}
	else if (params->modifier_h)
	{
		lo = (unsigned long int)va_arg(a, unsigned int);
	}
	else
	{
		lo = (unsigned int)va_arg(a, unsigned int);
	}

	s = convert(lo, 8, CONVERT_UNSIGNED, params);
	if (params->hashtag && lo)
	{
		*--s = '0';
	}
	params->unsigne = 1;
	return (i += print_number(s, params));
}
