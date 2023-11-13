#include "main.h"

/**
 * init_params - clear struct fields and reset buf
 * @params: the struct parameters
 * @a: the argument pointer
 * Return: void
 */

void init_params(params_t *params, va_list a)
{
	params->unsigne = 0;
	params->plus = 0;
	params->hashtag = 0;
	params->space = 0;
	params->zero = 0;
	params->minus = 0;
	params->width = 0;
	params->precision = UNIT_MAX;
	params->modifier_h = 0;
	params->modifier_l = 0;
	(void)a;
}
