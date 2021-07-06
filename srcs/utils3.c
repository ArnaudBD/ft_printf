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
	if (!(str = malloc(sizeof(char) * totalmem)))
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