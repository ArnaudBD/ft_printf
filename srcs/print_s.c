/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:49:55 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:52:18 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	len_calculator(const char *string, t_counters *countr, t_flag *flag)
{
	int	len;

	if (string != NULL)
		len = ft_strlen(string);
	else if (flag->dot == 1)
		len = flag->precision;
	else
	{
		countr->j += 6;
		if (flag->dot == 0 || flag->precision > 5)
			len = 6;
		else
			len = flag->precision;
	}
	return (len);
}

void	not_minus_handler(t_counters *countr, int l, const char *s, t_flag *f)
{
	if (f->dot == 1)
		not_m_but_dot_handler(countr, l, s, f);
	else
	{
		if (s == NULL)
			l = 0;
		while (f->width - (l + countr->j++) > 0)
			ft_putchar_ret(' ', f);
		if (s == NULL)
			countr->k = null_handler(countr, f);
		else
			while (s[countr->i] != 0)
				ft_putchar_ret(s[countr->i++], f);
	}
}

void	ft_norme(const char *string, t_counters *countr, t_flag *flag)
{
	while (flag->precision != 0 && string[countr->i] != 0)
	{
		ft_putchar_ret(string[countr->i++], flag);
		if (-flag->precision < flag->width && flag->precision > 0)
			flag->precision--;
	}
}

void	dot_minus_handler(const char *string, t_counters *countr, t_flag *flag)
{
	if (string == NULL)
		countr->k = null_handler(countr, flag);
	else if (flag->precision >= 0)
		ft_norme(string, countr, flag);
	else
		ft_norme(string, countr, flag);
	if (flag->width < 0)
		flag->width = -flag->width;
	while (flag->width - countr->i++ - countr->k > 0)
		ft_putchar_ret(' ', flag);
}

void	print_s(const char *string, t_flag *flag)
{
	int			len;
	t_counters	*countr;
	t_counters	a;

	countr = &a;
	countr_initializer(&a);
	len = len_calculator(string, countr, flag);
	if (flag->minus == 1)
	{
		if (flag->dot == 1)
			dot_minus_handler(string, countr, flag);
		else
		{
			if (string == NULL)
				countr->k = null_handler(countr, flag);
			else
				while (string[countr->i] != 0)
					ft_putchar_ret(string[countr->i++], flag);
			while (flag->width - countr->i++ - countr->k > 0)
				ft_putchar_ret(' ', flag);
		}
	}
	else
		not_minus_handler(countr, len, string, flag);
}
