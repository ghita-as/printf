#include "main.h"

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
