#include "../includes/ft_printf.h"

void	ft_putchar_ret(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->ret++;
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	int		totalmem;
	char	*str;

	i = 0;
	totalmem = count * size;
	str = malloc(sizeof(char) * totalmem);
	if (str == NULL)
		return (0);
	while (totalmem > 0)
	{
		str[i] = 0;
		i++;
		totalmem--;
	}
	return (str);
}

int	u_numlen(long long int number, t_flag *flag)
{
	int	magnitude;

	if (number == 0 && flag->precision == 0)
		return (0);
	magnitude = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 10;
		magnitude++;
	}
	return (magnitude);
}

int	is_flag(const char *str, int i)
{
	if (str[i] != '%' && str[i] != 'c' && str[i] != 's' && str[i] != 'p'
		&& str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
		&& str[i] != 'x' && str[i] != 'X' && str[i] != 0 && str[i] != '*'
		&& str[i] != '0' && str[i] != '.'
		&& !ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
		return (++i);
	return (i);
}
