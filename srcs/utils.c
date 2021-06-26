#include "../includes/ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_ret(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->ret++;
}

void	writing(long long int odg, long long int n, t_flag *flag)
{
	char	c;

	if (n == 0)
	{
		ft_putchar_ret('0', flag);
		return ;
	}
	while (odg > 1)
	{
		odg = odg / 10;
		c = n / odg + '0';
		if (ft_isdigit(c))
			ft_putchar_ret(c, flag);
		else
			break ;
		n = n - (n / odg) * odg;
	}
	return ;
}

void	isminmax(long long int n, t_flag *flag)
{
	if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		flag->ret = flag->ret + 10;
		return ;
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		flag->ret = flag->ret + 11;
		return ;
	}
}

void	ft_putnbr_ret(long long int n, t_flag *flag)
{
	long long int	odg;
	long long int	nb;

	odg = 1;
	nb = n;
	if (n == 2147483647 || n == -2147483648)
	{
		isminmax(n, flag);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_ret('-', flag);
		n = -n;
	}
	while (nb != 0 && odg != 0)
	{
		odg = odg * 10;
		nb = n;
		nb = nb / odg;
	}
	writing(odg, n, flag);
	return ;
}

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int resultat;

	i = 0;
	n = 1;
	resultat = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		resultat = 10 * resultat + str[i] - '0';
		i++;
	}
	return (resultat * n);
}
