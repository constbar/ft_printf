#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_properties
{
	int end_result;
	int precision;
	int negative;
	int spaces;
	int lenth;
	int width;
	int zeros;
	int zero;
	int dash;
	int dot;
}				t_properties;

int				ft_printf(const char *str, ...);
void			ft_handle_dot(va_list ap, t_properties *prop, const char **str);
void			ft_handle_dash(va_list ap, t_properties *prop, const char **s);
void			ft_handle_star(va_list ap, t_properties *prop, const char **s);
void			ft_handle_zero(t_properties *prop, const char **str);
void			ft_handle_uint(va_list ap, t_properties *prop, const char **s);
void			ft_handle_int(va_list ap, t_properties *prop, const char **str);
void			ft_handle_adr(va_list ap, t_properties *prop, const char **str);
void			ft_handle_hex(va_list ap, t_properties *prop, const char **str);
int				ft_count_len_num(int digit);
int				ft_count_len_unum(unsigned int digit);
int				ft_count_len_hex(unsigned long digit);
int				ft_handle_digit(const char **str);
size_t			ft_strlen_def(const char *str);
void			ft_print_perc(t_properties *prop, const char **str);
void			ft_output_str(char *s, t_properties *prop);
void			ft_print_char(va_list ap, t_properties *prop, const char **str);
void			ft_output_char(char c, t_properties *prop);
void			ft_putnbr_hex(unsigned long n, t_properties *prop, char letter);
void			ft_putnbr_uint(unsigned int n, t_properties *prop);
void			ft_putnbr_int(int n, t_properties *prop);
void			ft_print_space(int num_of_spaces, t_properties *prop);
void			ft_print_zeros(int num_of_zeros, t_properties *prop);
void			ft_handle_str(va_list ap, t_properties *prop, const char **str);
void			ft_print_str(t_properties *prop, char **str, int slen);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);

#endif
