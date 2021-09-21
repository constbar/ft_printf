#include "../libftprintf.h"

void	ft_handle_dot(va_list ap, t_properties *prop, const char **str)
{
	prop->dot = 1;
	(*str)++;
	if (**str == '*')
	{
		prop->precision = va_arg(ap, int);
		if (prop->precision < 0)
		{
			prop->dot = 0;
			prop->precision = 0;
		}
		(*str)++;
	}
	else
		prop->precision = ft_handle_digit(str);
}

void	ft_handle_dash(va_list ap, t_properties *prop, const char **s)
{
	prop->dash = 1;
	prop->zero = 0;
	while (**s == '-')
		(*s)++;
	if (**s == '*')
	{
		prop->width = va_arg(ap, int);
		prop->width < 0 ? prop->width *= (-1) : 0;
		(*s)++;
	}
}

void	ft_handle_star(va_list ap, t_properties *prop, const char **s)
{
	prop->width = va_arg(ap, int);
	if (prop->width < 0)
	{
		prop->width *= (-1);
		prop->dash = 1;
		prop->zero = 0;
	}
	(*s)++;
	**s == '.' ? ft_handle_dot(ap, prop, s) : 0;
}

void	ft_handle_zero(t_properties *prop, const char **str)
{
	prop->zero = 1;
	while (**str == '0')
		(*str)++;
}
