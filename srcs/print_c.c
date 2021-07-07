/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:49:41 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:51:48 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_c(const void *c, t_flag *flag)
{
	if (flag->minus == 1)
	{
		write(1, &c, 1);
		flag->ret++;
	}
	while (flag->width > 1)
	{
		write(1, " ", 1);
		flag->width--;
		flag->ret++;
	}
	if (flag->minus == 0)
	{
		write(1, &c, 1);
		flag->ret++;
	}
	return ;
}
