#include "../libftprintf.h"

int		ft_count_len_num(int digit)
{
	int i;

	i = 0;
	if (digit <= 0)
		i = i + 1;
	while (digit)
	{
		digit /= 10;
		i++;
	}
	return (i);
}

int		ft_count_len_unum(unsigned int digit)
{
	int i;

	i = 0;
	if (digit == 0)
		i = i + 1;
	while (digit)
	{
		digit /= 10;
		i++;
	}
	return (i);
}

int		ft_count_len_hex(unsigned long digit)
{
	int		i;

	i = 0;
	if (digit == 0)
		i++;
	while (digit != 0)
	{
		digit = digit / 16;
		i++;
	}
	return (i);
}

int		ft_handle_digit(const char **str)
{
	int	i;

	i = 0;
	while (**str >= '0' && **str <= '9')
	{
		i = i * 10;
		i = **str - 48 + i;
		(*str)++;
	}
	return (i);
}

size_t	ft_strlen_def(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
