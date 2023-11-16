#include "main.h"

/**
 * _printf - Custom printf function with limited functionality
 * @format: Format string with directives
 * @...: Variable number of arguments
 *
 * This function prints formatted output to the standard output.
 * The format string may contain conversion specifiers such as '%c', '%s', and '%%'.
 * It supports basic formatting options but does not handle all features of the standard printf.
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int s = 0; /* Variable to track the number of characters printed */
	va_list a; /* Variable argument list */
	char *p, *start; /* Pointers for iterating through the format string */
	params_t params = PARAMS_INIT; /* Initialize parameters struct */

	va_start(a, format);

	/* Check for invalid format string */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_params(&params, a);

		/* If the current character is not '%', print it and continue */
		if (*p != '%')
		{
			s += _putchar(*p);
			continue;
		}

		start = p; /* Save the starting position of the specifier */
		p++;

		/* Process flags and modifiers */
		while (get_flags(p, &params))
		{
			p++;
		}

		/* Get width and precision values */
		p = get_width(p, &params, a);
		p = get_precision(p, &params, a);

		/* Check if the specifier is valid, then call the appropriate function */
		if (!get_specifier(p))
		{
			s += print_from_to(start, p, params.modifier_l || params.modifier_h ? p - 1 : 0);
		}
		else
		{
			s += get_print_function(p, a, &params);
		}
	}

	_putchar(BUF_FLUSH);
	va_end(a);

	return (s);
}
