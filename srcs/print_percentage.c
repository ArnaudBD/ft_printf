/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:49:52 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:52:15 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_percentage(t_flag *flag)
{
	int	i;

	i = flag->width;
	if (flag->zero == 1 && flag->minus == 0)
	{
		while (i > 1)
		{
			ft_putchar_ret('0', flag);
			i--;
		}
	}
	else if (flag->minus == 0)
	{
		while (i > 1)
		{
			ft_putchar_ret(' ', flag);
			i--;
		}
	}
	ft_putchar_ret('%', flag);
	if (flag->minus == 1)
		while (i-- > 1)
			ft_putchar_ret(' ', flag);
}
