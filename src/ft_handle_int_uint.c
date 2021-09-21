#include "../libftprintf.h"

static	void	ft_print_int(t_properties *prop, int digit)
{
	prop->dash == 0 ? ft_print_space(prop->spaces, prop) : 0;
	if (prop->negative == 1 && digit > -2147483648)
	{
		digit = digit * -1;
		ft_output_char('-', prop);
	}
	digit == -2147483648 ? ft_output_char('-', prop) : 0;
	prop->zeros > 0 ? ft_print_zeros(prop->zeros, prop) : 0;
	if (digit == -2147483648)
		ft_output_str("2147483648", prop);
	else if (prop->lenth > 0)
		ft_putnbr_int(digit, prop);
	prop->dash == 1 ? ft_print_space(prop->spaces, prop) : 0;
}

void			ft_handle_int(va_list ap, t_properties *prop, const char **str)
{
	int digit;

	(*str)++;
	digit = va_arg(ap, int);
	prop->lenth = ft_count_len_num(digit);
	digit < 0 ? prop->negative = 1 : 0;
	if (prop->dot == 1 && digit == 0)
	{
		prop->zeros = prop->precision;
		prop->lenth = 0;
	}
	prop->precision > prop->lenth - prop->negative
	? prop->zeros = prop->precision
	- prop->lenth + prop->negative : 0;
	prop->dash == 0 && prop->dot == 0 && prop->zero == 1 && prop->width
	> prop->lenth ? prop->zeros = prop->width - prop->lenth : 0;
	prop->width > prop->precision ? prop->spaces = prop->width
	- prop->zeros - prop->lenth : 0;
	ft_print_int(prop, digit);
}

static	void	ft_print_uint(t_properties *prop, unsigned int digit)
{
	prop->dash == 0 ? ft_print_space(prop->spaces, prop) : 0;
	prop->zeros > 0 ? ft_print_zeros(prop->zeros, prop) : 0;
	prop->lenth > 0 ? ft_putnbr_uint(digit, prop) : 0;
	prop->dash == 1 ? ft_print_space(prop->spaces, prop) : 0;
}

void			ft_handle_uint(va_list ap, t_properties *prop, const char **s)
{
	unsigned int num;

	(*s)++;
	num = va_arg(ap, unsigned int);
	prop->lenth = ft_count_len_unum(num);
	if (prop->dot == 1 && num == 0)
	{
		prop->zeros = prop->precision;
		prop->lenth = 0;
	}
	prop->precision > prop->lenth ? prop->zeros = prop->precision
	- prop->lenth : 0;
	prop->zero == 1 && prop->width
	> prop->lenth && prop->dash == 0 && prop->dot == 0
	? prop->zeros = prop->width - prop->lenth : 0;
	prop->width > prop->precision ? prop->spaces = prop->width
	- prop->zeros - prop->lenth : 0;
	ft_print_uint(prop, num);
}
