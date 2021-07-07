/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:50:13 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:52:25 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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
		write(1, "2147483648", 10);
		flag->ret = flag->ret + 10;
		return ;
	}
}

void	ft_putnbr_ret(long long int n, t_flag *flag)
{
	long long int	odg;
	long long int	nb;

	odg = 1;
	nb = n;
	if (n < 0)
	{
		if (flag->dot == 0 || n == -2147483648)
			ft_putchar_ret('-', flag);
		n = -n;
	}
	if (n == 2147483647 || n == -2147483648)
	{
		isminmax(n, flag);
		return ;
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

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	resultat;

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
