/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:49:58 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:52:20 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_zeros(long long int number, t_counters *countr, t_flag *flag)
{
	while (countr->i < (flag->precision - numlen(number)))
	{
		ft_putchar_ret('0', flag);
		countr->i++;
	}
}

void	u_minus_handler(long long int number, t_counters *countr, t_flag *flag)
{
	if (flag->precision <= flag->width)
	{
		print_zeros(number, countr, flag);
		if (countr->i != 0)
			countr->j = flag->precision;
		else if (flag->dot != 1 || flag->precision != 0 || number != 0)
			countr->j = numlen(number);
		countr->i = 0;
		if (flag->dot != 1 || flag->precision != 0 || number != 0)
			ft_putnbr_ret(number, flag);
		while ((flag->width - countr->j) > countr->i)
		{
			ft_putchar_ret(' ', flag);
			countr->i++;
		}
	}
	else if (flag->precision > numlen(number))
	{
		print_zeros(number, countr, flag);
		if (flag->dot != 1 || flag->precision != 0 || number != 0)
			ft_putnbr_ret(number, flag);
	}
}

void	u_not_minus_handler(long long int n, t_counters *countr, t_flag *flag)
{
	while (!(flag->zero == 1 && flag->dot == 0)
		&& ((flag->width - (countr->j + flag->precision)) > countr->i
			&& (flag->width - (countr->j + numlen(n))) > countr->i++))
	{
		if (flag->zero == 1 && flag->precision < 0)
			ft_putchar_ret('0', flag);
		else
			ft_putchar_ret(' ', flag);
	}
	countr->i = 0;
	if (flag->precision > flag->width)
		print_zeros(n, countr, flag);
	else if (flag->zero == 1 && flag->dot == 0)
	{
		while ((flag->width - (countr->j + numlen(n))) > countr->i++)
			ft_putchar_ret('0', flag);
	}
	print_zeros(n, countr, flag);
	if (flag->dot == 1 && flag->precision == 0 && n == 0
		&& (numlen(n) <= flag->width || numlen(n) < flag->precision))
		ft_putchar_ret(' ', flag);
	else if (flag->dot != 1 || flag->precision != 0 || n != 0)
		ft_putnbr_ret(n, flag);
}

void	print_u(unsigned int number, t_flag *flag)
{
	t_counters	a;
	t_counters	*countr;

	countr = &a;
	countr->i = 0;
	countr->j = 0;
	if (numlen(number) >= flag->width && numlen(number) >= flag->precision
		&& (flag->dot != 1 || flag->precision != 0 || number != 0))
		ft_putnbr_ret(number, flag);
	else if (flag->minus == 1)
		u_minus_handler(number, countr, flag);
	else
	{
		countr->i = 0;
		if (number < 0)
			countr->j = 1;
		u_not_minus_handler(number, countr, flag);
	}
	return ;
}
