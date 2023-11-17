#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
<<<<<<< HEAD
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
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
>>>>>>> 96ee2dba2479de758984df88fee3f449e79dfc69
}

