/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_num_sz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agroup <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:12:36 by agroup            #+#    #+#             */
/*   Updated: 2020/12/15 16:12:44 by agroup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex(unsigned long n, t_properties *prop, char letter)
{
	if (n < 10)
		ft_output_char(n + '0', prop);
	else if (letter == 'X' && n > 9 && n < 16)
		ft_output_char((70 - (15 - n)), prop);
	else if (letter == 'x' && n > 9 && n < 16)
		ft_output_char((102 - (15 - n)), prop);
	else
	{
		ft_putnbr_hex(n / 16, prop, letter);
		ft_putnbr_hex(n % 16, prop, letter);
	}
}

void	ft_putnbr_uint(unsigned int n, t_properties *prop)
{
	if (n < 10)
		ft_output_char(n + '0', prop);
	else
	{
		ft_putnbr_uint(n / 10, prop);
		ft_putnbr_uint(n % 10, prop);
	}
}

void	ft_putnbr_int(int n, t_properties *prop)
{
	if (n == -2147483648)
	{
		ft_output_char('-', prop);
		ft_output_str("-2147483648", prop);
	}
	else if (n < 0)
	{
		ft_output_char('-', prop);
		ft_putnbr_int(n * (-1), prop);
	}
	else if (n >= 10)
	{
		ft_putnbr_int(n / 10, prop);
		ft_putnbr_int(n % 10, prop);
	}
	else
		ft_output_char(n + '0', prop);
}

void	ft_print_space(int num_of_spaces, t_properties *prop)
{
	while (num_of_spaces > 0)
	{
		prop->end_result++;
		write(1, " ", 1);
		num_of_spaces--;
	}
}

void	ft_print_zeros(int num_of_zeros, t_properties *prop)
{
	while (num_of_zeros > 0)
	{
		prop->end_result++;
		write(1, "0", 1);
		num_of_zeros--;
	}
}
