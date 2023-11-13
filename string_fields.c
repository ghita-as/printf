#include "main.h"

/**
 * get_precision - this function gets the precision from format string
 * @p: the format string
 * @params: the parameters struct
 * @a: the argument pointer
 * Return: returns the new pointer
 */

char *get_precision(char *p, params_t *params, va_list a)
{
	int c = 0;

	if (*p != '.')
	{
		return (p);
	}
	p++;
	if (*p == '*')
	{
		c = va_arg(a, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = c;
	return (p);
}
