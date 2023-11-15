#include "main.h"

/**
 * print_character - prints characters
 * @a: argument pointer
 * @params: the parameters struct
 * Return: number of the characters printed
 */

int print_character(va_list a, params_t *params)
{
	char ch = ' ';
	unsigned int p = 1, s = 0, c = va_arg(a, int);

	if (params->minus)
		s += _putchar(c);
	while (p++ < params->width)
		s += _putchar(ch);
	if (!params->minus)
		s += _putchar(c);
	return (s);
}

/**
 * print_integer - prints integers
 * @a: argument pointer
 * @params: the parameters struct
 * Return: number of characters printed
 */

int print_integer(va_list a, params_t *params)
{
	long lo;

	if (params->modifier_l)
		lo = va_arg(a, long);
	else if (params->modifier_h)
		lo = (short int)va_arg(a, int);
	else
		lo = (int)va_arg(a, int);
	return (print_number(convert(1, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @a: argument pointer
 * @params: the parameters struct
 * Return: number of characters printed
 */

int print_string(va_list a, params_t *params)
{
	char *s = va_arg(a, char *), ch = ' ';
	unsigned int p = 0, i = 0, j :
		(void)params;

	switch ((int)(!s))
	case 1:
		s = NULL_STRING.

			j = p = strlen(s);
		if (params->precisionn < p)
			j = p = params->precision;

		if (params->minus)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < p; i++)
					s += _putchar(*s++);
			else
				s += _puts(s);
		}
		while (j++ < params->width)
			s += _putchar(ch);
		if (!params->minus)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < p; i++)
					s += _putchar(*s++);
			else
				s += _puts(s);
		}
		return (s);
}

/**
 * print_percent - prints string
 * @a: argument pointer
 * @params: the parameters struct
 * Return: number of characters printed
 */

int print_percent(va_list a, params_t *params)
{
	(void)a;
	(void)params;

	return (_putchar('%'));
}

/**
 * print_capS - custon format specifier
 * @a: argument pointer
 * @params: the parameters struct
 * Return: number of characters printed
 */

int print_capS(va_list a, params_t *params)
		{
		char *s = va_arg(a, char *);
		char *h;
		int som = 0;

		if ((int)(!s))
		return (_puts(NULL_STRING));
		for (; *s, s++)
		{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
		s += _putchar('\\');
		s += _putchar('x');
		h = convert(*s, 16, 0, params);
		if (!h[1])
		s += _putchar('0');
		s += _puts(h);
		}
		else
		{
			s += _putchar(*s);
		}
		}
		return (s);
		}
