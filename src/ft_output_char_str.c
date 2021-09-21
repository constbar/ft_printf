#include "../libftprintf.h"

void	ft_print_perc(t_properties *prop, const char **str)
{
	(*str)++;
	prop->width > 1 ? prop->spaces = prop->width - 1 : 0;
	prop->dash == 0 ? ft_print_space(prop->spaces, prop) : 0;
	ft_output_char('%', prop);
}

void	ft_output_str(char *s, t_properties *prop)
{
	if (!s)
		return ;
	while (*s)
		ft_output_char(*s++, prop);
}

void	ft_print_char(va_list ap, t_properties *prop, const char **str)
{
	(*str)++;
	prop->width > 1 ? prop->spaces = prop->width - 1 : 0;
	prop->zero == 1 ? prop->zeros = prop->width - 1 : 0;
	if (prop->dash == 0 && prop->zero == 0)
		ft_print_space(prop->spaces, prop);
	else if (prop->zeros > 0)
		ft_print_zeros(prop->zeros, prop);
	ft_output_char((char)(va_arg(ap, int)), prop);
	prop->dash == 1 ? ft_print_space(prop->spaces, prop) : 0;
}

void	ft_output_char(char c, t_properties *prop)
{
	prop->end_result++;
	write(1, &c, 1);
}
