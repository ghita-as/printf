#include "main.h"

/**
 * print_from_to - prints a range of characters addresses
 * @begin: the starting adress
 * @end: the stopping address
 * @ex: the except adress
 * Return: the printed bytes number
 */

int print_from_to(char *begin, char *end, char *ex)
{
	int a = 0;

	while (begin <= end)
	{
		if (begin != except)
			a += _putchar(*begin);
		begin++;
	}
	return (a);
}

/**
 * print_reverse - this function prints the string in reverse
 * @a: string
 * @params: the parameters struct
 * Return: tne printers bytes number
 */

int print_reverse(va_list a, params_t *params)
{
	int lengh, summ = 0;
	char *str = va_arg(a, char *);
	(void)params;

	if (str)
	{
		for (lengh = 0; *str; str++)
			lengh++;
		str--;
		for (; lengh > 0; lengh--, str--)
			summ += _putchar(*str);
	}
	return (summ);
}

/**
 * print_rot13 - prints string in rotation
 * @a: the string
 * @params: the parameters struct
 * Return: the printed bytes number
 */

int print_rot13(va_list a, params_t *params)
{
	int i, j;
	int c = 0;
	char ar[] = "ABCDEFGHIJKLMOPQRSTUVWXYZ  abcdefjhijklmnopqrstuvwxyz";
	char *s = va_arg(a, char *);
	(void)params;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] >= 'A' && a[i] <= 'Z')
				|| (s[i] >= 'a' && s[i] <= 'z'))
		{
			j = s[i] - 65;
			c += _putchar(ar[j]);
		}
		else
			c = _putchar(ar[i]);
		i++;
	}
	return (c);
}
