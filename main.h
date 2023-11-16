#ifndef _PRINT_H
#define _PRINT_H

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct parameters - parameters struct
 * @unsigne: if unsigne value then flag
 * @plus: if plus is specified then on
 * @hashtag: on if hashtag specified
 * @space: if space specified then on
 * @zero: if zero specified then on
 * @minus: if minus specified then on
 * @width: width field is specified
 * @precision: precision field is specified
 * @modifier_h: on if mofifier_h is specified
 * @modifier_l: on if modifier_l is specified
 */

typedef struct parameters
{
	unsigned int unsigne :1;
	unsigned int plus :1;
	unsigned int space :1;
	unsigned int hashtag :1;
	unsigned int zero :1;
	unsigned int minus :1;
	unsigned int width;
	unsigned int precision;
	unsigned int modifier_h :1;
	unsigned int modifier_l :1;
} params_t;

/**
 * struct specifier - struct
 * @specifier : format token
 * @s : associatef function
 */

typedef struct specifier
{
	char *specifier;
	int (*s)(va_list, params_t *);
} specifier_t;

/*_ put modules*/
int _puts(char *str);
int _putchar(int c);

/* print_functions modules*/
int print_character(va_list a, params_t *params);
int print_integer(va_list a, params_t *params);
int print_string(va_list a, params_t *params);
int print_percent(va_list a, params_t *params);
int print_capS(va_list a, params_t *params);

/* number.c modules*/
char *convert(long int n, int b, int f, params_t *params);
int print_unsigned(va_list a, params_t *params);
int print_address(va_list a, paramss_t *params);

/* specifier.c modules*/
int (*get_specifier(char *s))(va_list a, params_t *params);
int get_print_function(char *s, va_list a, params_t *params);
int get_flags(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list a);

/* convert_number.c modules*/
int prin_hexa(va_list a, params_t *params);
int print_HEXA(va_list a, params_t *params);
int print_binary(va_list a, params_t *params);
int print_octal(va_list a, params_t *params);

/* simple_printers.c modules*/
int print_from_to(char *begin, char *end, char *ex);
int print_reverse(va_list a, params_t *params);
int print_rot13(va_list a);

/* print_number.c modules*/
int _isdigit(int d);
int _strlen(char *s);
int print_number(char *s, params_t *params);
int print_number_right(char *s, params_t *params);
int print_number_left(char *s, params_t *params);

/* params.c modules*/
void init_params(params_t *params, va_list a);

/* string_fields.c modules*/
char *get_precision(char *p, params_t *params, va_list a);

/* _printf.c module */
int _printf(const char *format, ...);

#endif
