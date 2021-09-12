/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str_libft.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agroup <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:13:09 by agroup            #+#    #+#             */
/*   Updated: 2020/12/15 16:32:56 by agroup           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_str(t_properties *prop, char **str, int slen)
{
	if (prop->dash == 0 && prop->zero == 0)
		ft_print_space(prop->spaces, prop);
	else if (prop->zero == 1)
		ft_print_zeros(prop->spaces, prop);
	while (slen--)
	{
		ft_output_char(**str, prop);
		(*str)++;
	}
	prop->dash == 1 ? ft_print_space(prop->spaces, prop) : 0;
}

void	ft_handle_str(va_list ap, t_properties *prop, const char **str)
{
	int		slen;
	char	*s;

	(*str)++;
	s = va_arg(ap, char *);
	s == NULL ? s = "(null)" : 0;
	slen = ft_strlen_def(s);
	prop->dot == 1 && prop->precision < slen ? slen = prop->precision : 0;
	if (prop->width >= slen)
	{
		if (prop->dot == 1)
			prop->spaces = prop->width - slen;
		else
			prop->spaces = prop->width - prop->precision - slen;
	}
	ft_print_str(prop, &s, slen);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char *)b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char *)s;
	while (*p && *p != c)
		p++;
	if (*p == c)
		return (p);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	ft_memset(p, '\0', n);
}
