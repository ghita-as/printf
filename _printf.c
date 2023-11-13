#include "main.h"

/**
 * _printf - Custom printf function with limited functionality
 * This function prints formatted output to the standard output
 *
 * @format: Format string with directives it may contain conversion specifiers
 * such as '%c', '%s', and '%%'and it supports basic formatting options
 * but does not handle all features of the standard printf.
 *
 * Return: Number of characters printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	int s = 0;
	va_list a;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(a, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, a);
		if (*p != '%')
		{
			s += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flags(p, &params)) /* while char at p is flag character*/
		{
			p++; /* next character*/
		}
		p = get_width(p, &params, a);
		p = get_precision(p, &params, a);
		if (!get_specifier(p))
		{
			sum += print_from_to(start, p,
					params.modifier_l || params.modifier_h ? p - 1 : 0);
		}
		else
		{
			sum += get_print_function(p, a, &params);
		}
	}
	_putchar(BUF_FLUSH);
	va_end(a);
	return (s);
}
