#include "main.h"

/**
 * convert - this is a converter function
 * @n: number
 * @b: base
 * @f: argument flag
 * @params: parameters struct
 * Return: string
 */

char *convert(long int n, int b, int f, params_t *params)
{
	static char *ar;
	static char buf[50];
	char sig = 0;
	char *ptr;
	unsigned long nu = n;
	(void)params;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		nu = -n;
		sig = '-';
	}
	ar = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do {
		*--ptr = ar[nu % b];
		n /= b;
	} while (nu != 0);

	if (sig)
		*--ptr = sig;
	return (ptr);
}

/**
 * print_unsigned - this function prints unsigned integer numbers
 * @a: argument pointer
 * @params: the parameters struct
 * Return: the printed bytes
 */

int print_unsigned(va_list a, params_t *params)
{
	unsigned long q;

	if (params->modifier_l)
		q = (unsigned long)va_arg(a, unsigned long);
	else if (params->modifier_h)
		q = (unsigned short int)va_arg(a, unsigned int);
	else
		q = (unsigned int)va_arg(a, unsigned int);
	params->unsigne = 1;
	return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - this function prints address
 * @a: argument pointer
 * @params: parameters struct
 * Return: printed bytes
 */

int print_address(va_list a, paramss_t *params)
{
	unsigned long int d = va_arg(a, unsigned long int);
	char *str;

	if (!d)
		return (_puts("(null)"));

	str = convert(d, 16, CONVERT_USIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
