#include "../libftprintf.h"

static	void	ft_check_type(va_list ap, t_properties *prop, const char **str)
{
	if (**str == '%')
		ft_print_perc(prop, str);
	else if (**str == 'c')
		ft_print_char(ap, prop, str);
	else if (**str == 's')
		ft_handle_str(ap, prop, str);
	else if (**str == 'd')
		ft_handle_int(ap, prop, str);
	else if (**str == 'i')
		ft_handle_int(ap, prop, str);
	else if (**str == 'p')
		ft_handle_adr(ap, prop, str);
	else if (**str == 'x')
		ft_handle_hex(ap, prop, str);
	else if (**str == 'X')
		ft_handle_hex(ap, prop, str);
	else if (**str == 'u')
		ft_handle_uint(ap, prop, str);
}

static	void	ft_handle_flag(va_list ap, t_properties *prop, const char **str)
{
	while (**str)
	{
		(*str)++;
		**str == '0' ? ft_handle_zero(prop, str) : 0;
		**str == '-' ? ft_handle_dash(ap, prop, str) : 0;
		**str >= '0' && **str <= '9' ? prop->width = ft_handle_digit(str) : 0;
		**str == '.' ? ft_handle_dot(ap, prop, str) : 0;
		**str == '*' ? ft_handle_star(ap, prop, str) : 0;
		ft_strchr("cspdiuxX%", **str) ? ft_check_type(ap, prop, str) : 0;
		return ;
	}
}

int				ft_printf(const char *str, ...)
{
	int				result;
	t_properties	prop;
	va_list			ap;

	va_start(ap, str);
	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_bzero(&prop, sizeof(t_properties));
			ft_handle_flag(ap, &prop, &str);
			result = result + prop.end_result;
		}
		else
		{
			ft_output_char(*str, &prop);
			result++;
			str++;
		}
	}
	va_end(ap);
	return (result);
}
