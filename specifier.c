#include "main.h"

/**
 * get_specifier - finds the function's format
 * @s: the string format
 * Return: theprinted bytes number
 */

int (*get_specifier(char *s))(va_list a, params_t *params)
{
	specifier_t spec[] = {
		{"c", print_character},
		{"d", print_integer},
		{"d", print_integer},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hexa},
		{"X", print_HEXA},
		{"p", print_address},
		{"S", print_capS},
		{"r", print_reverse},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (spec[i].specifier)
	{
		if (*s == spec[i].specifier[0])
		{
			return (spec[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_function - finds the format function
 * @s: the format string
 * @a: argument pointer
 * @params: the parameters struct
 * Return: printed bytes number
 */

int (*get_specifier(char *s))(va_list a, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
	{
		return (f(a, params));
	}
	return (0);
}

/**
 * get_flags - finds the flag function
 * @s: the string format
 * @params: the parameters struct
 * Return: if flag was valid
 */

int get_flags(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus = 1;
			break;
		case ' ':
			i = params->space = 1;
			break;
		case '#':
			i = params->hashtag = 1;
			break;
		case '-':
			i = params->minus = 1;
			break;
		case '0':
			i = params->zero = 1;
			break;
	}
	return (1);
}

/**
 * get_modifier - finds the modifier function
 * @s: the string format
 * @params: the parameters struct
 * Return: if modifier was valid
 */

int get_modifier(char *s, params_t *params)
{
	int = 0;

	switch (*s)
	{
		case 'h':
			i = params->modifier_h = 1;
			break;
		case 'l':
			i = params->modifier_l = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @a: the argument pointer
 * Return: new pointer
 */

char *get_width(char *s, params_t *params, va_list a)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(a, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
