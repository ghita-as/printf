#include "main.h"

/**
 * _isdigit - this function checks if the character printed is a digit
 * @d:the character to be checked
 * Return: 1 if digit otherwise 0
 */

int _isdigit(int d)
{
	return (d >= '0' && d <= '9');
}

/**
 * _strlen - this function returns the length of a string
 * @s: the string
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints number according to the options
 * @s: the base number in string format
 * @params: the parameters struct
 * Return: characters printed
 */

int print_number(char *s, params_t *params)
{
	unsigned int i = _strlen(s);
	int n = (!params->unsigne && *s == '-');

	if (!params->precision && *s == '0' && !s[1])
		s = "";
	if (n)
	{
		s++;
		i--;
	}
	if (params->precision != UNIT_MAX)
		while (i++ < params->precision)
			*--s = '0';
	if (n)
		*--s = '-';

	if (!params->minus)
		return (print_number_right(s, params));
	else
		return (print_number_left(s, params));
}

/**
 * print_number_right - prints a number with options
 * @s: the base number as a string
 * @params: the parameters struct
 * Return: characters printed
 */

int print_number_right(char *s, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(s);
	char p_char = ' ';

	if (params->zero && !params->minus)
		p_char - '0';
	n1 = n2 = (!params->unsigne && *s == '-');
	if (n1 && i < params->width && p_char == '0' && !prams->minus)
		s++;
	else
		n1 = 0;
	if ((params->plus && !n2) || (!params->plus && params->space && !n2))
		i++;
	if (n1 && p_char == '0')
		n += _putchar('-');
	if (params->plus && !n2 && p_char == '0' && !params->unsigne)
		n += _putchar('+');
	else if (!params->plus && params->space && !n2 && !params->unsigne &&
			params->zero)
		n += _putchar(p_char);
	while (i++ < params->width)
		n += _putchar(p_char);
	if (n1 && p_char == ' ')
		n += _putchar('-');
	if (params->plus && !n2 && p_char == ' ' && !params->unsigne)
		n += _putchar('+');
	else if (!params->plus && params->space && !n2 &&
			!params->unsigne && !params->zero)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}

/**
 * print_number_left - prints number with options
 * @s: the base number as a string
 * @params: the parameters struct
 * Return: characters printed
 */

int print_number_left(char *s, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(s);
	char p_char = ' ';

	if (params->zero && !params->minus)
		p_char = '0';
	n1 = n2 = (!params->unsigne && *s == '-');
	if (n1 && i < params->width && p_char == '0' && !params->minus)
		s++;
	else
		n1 = 0;
	if (params->plus && !n2 && !params->unsigne)
		n += _putchar('+'), i++;
	else if (params->space && !n2 && !params->unsigne)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < params->width)
		n += _putchar(p_char);
	return (n);
}
