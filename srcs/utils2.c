/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:50:22 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:52:27 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	numlen(long long int number)
{
	int	magnitude;

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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	flag_initializer(t_flag *a)
{
	a->minus = 0;
	a->dot = 0;
	a->width = 0;
	a->zero = 0;
	a->precision = 0;
}

void	countr_initializer(t_counters *a)
{
	a->i = 0;
	a->j = 0;
	a->k = 0;
}

int	null_handler(t_counters *c, t_flag *f)
{
	char	*n;

	n = "(null)";
	if (c->i > f->precision)
		c->i = f->precision;
	if (f->minus == 1)
	{
		if (f->dot == 1 && (f->precision < 0
				|| (f->precision != c->i && f->precision <= 0)))
			f->precision = 6;
		while ((c->k < 6 && c->k < f->precision)
			|| (f->dot == 0 && f->precision == 0 && c->k < 6))
			ft_putchar_ret(n[c->k++], f);
	}
	else
	{
		if (f->dot == 1)
			while (c->k < 6 && (c->k < f->precision || f->precision < 0))
				ft_putchar_ret(n[c->k++], f);
		else
			while (c->k < 6 && (f->precision == 0 || c->k < f->precision))
				ft_putchar_ret(n[c->k++], f);
	}
	return (c->k);
}
