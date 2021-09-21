#include "../libftprintf.h"

static	void	ft_print_hex(t_properties *prop, unsigned long num, char letter)
{
	prop->dash == 0 ? ft_print_space(prop->spaces, prop) : 0;
	prop->zeros > 0 ? ft_print_zeros(prop->zeros, prop) : 0;
	prop->lenth > 0 ? ft_putnbr_hex(num, prop, letter) : 0;
	prop->dash == 1 ? ft_print_space(prop->spaces, prop) : 0;
}

void			ft_handle_hex(va_list ap, t_properties *prop, const char **str)
{
	char			letter;
	unsigned long	digit;

	letter = **str;
	(*str)++;
	digit = va_arg(ap, unsigned int);
	prop->lenth = ft_count_len_hex(digit);
	if (prop->dot == 1 && digit == 0)
	{
		prop->zeros = prop->precision;
		prop->lenth = 0;
	}
	prop->precision > prop->lenth ? prop->zeros = prop->precision
	- prop->lenth : 0;
	prop->zero == 1 && prop->width
	> prop->lenth && prop->dot == 0 && prop->dash == 0
	? prop->zeros = prop->width - prop->lenth : 0;
	prop->width > prop->precision ? prop->spaces = prop->width
	- prop->zeros - prop->lenth : 0;
	ft_print_hex(prop, digit, letter);
}

static	void	ft_print_adr(t_properties *prop, unsigned long num)
{
	prop->dash == 0 ? ft_print_space(prop->spaces, prop) : 0;
	ft_output_str("0x", prop);
	prop->zeros > 0 ? ft_print_zeros(prop->zeros, prop) : 0;
	prop->lenth > 0 ? ft_putnbr_hex(num, prop, 'x') : 0;
	prop->dash == 1 ? ft_print_space(prop->spaces, prop) : 0;
}

void			ft_handle_adr(va_list ap, t_properties *prop, const char **str)
{
	unsigned long	digit;

	(*str)++;
	digit = va_arg(ap, unsigned long);
	prop->lenth = ft_count_len_hex(digit);
	if (prop->dot == 1 && digit == 0)
	{
		prop->zeros = prop->precision;
		prop->lenth = 0;
	}
	prop->precision > prop->lenth ? prop->zeros = prop->precision
	- prop->lenth : 0;
	prop->zero == 1 && prop->width > prop->lenth && prop->dot == 0
	&& prop->dash == 0 ? prop->zeros = prop->width - prop->lenth - 2 : 0;
	prop->width > prop->precision ? prop->spaces = prop->width
	- prop->zeros - prop->lenth - 2 : 0;
	ft_print_adr(prop, digit);
}
