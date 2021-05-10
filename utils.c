#include "ft_printf.h"

void	print_hex(int nbr)
{
	int		i;
	int		j;
	int		div;
	int		quo;
	char	base[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = 0;
	j = 0;
	div = nbr / 16;
	quo = nbr % 16;

	while (div != 0)
	{
		div = quo / 16;
		quo = quo % 16;
		i++;
	}
	while (i != 0)
	{
		while (j != i)
		{
			write
			j++;
		}
		i--;
	}


	return (hex);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	writing(int odg, int n, int fd)
{
	char	c;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	while (odg > 1)
	{
		odg = odg / 10;
		c = n / odg + '0';
		ft_putchar_fd(c, fd);
		n = n - (n / odg) * odg;
	}
	return ;
}

void	isminmax(int n, int fd)
{
	if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int			odg;
	long int	nb;

	odg = 1;
	nb = n;
	if (n == 2147483647 || n == -2147483648)
	{
		isminmax(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (nb != 0 && odg != 0)
	{
		odg = odg * 10;
		nb = n;
		nb = nb / odg;
	}
	writing(odg, n, fd);
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

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}