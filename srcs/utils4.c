/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:50:38 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:51:08 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_not_minus_handler(unsigned int number, char *c, t_flag *f, char *bas)
{
	if ((f->zero == 1 && f->precision < 0) || (f->zero == 1 && f->dot == 0))
	{
		if (f->precision < reslen(number, bas, f))
			print_xchar(f->width - reslen(number, bas, f), '0', f);
		else if (f->precision > 0)
			print_xchar(f->precision - reslen(number, bas, f), '0', f);
	}
	else if (f->precision <= f->width)
	{
		if (f->precision < reslen(number, bas, f))
			print_xchar(f->width - reslen(number, bas, f), ' ', f);
		else
			print_xchar(f->width - f->precision, ' ', f);
		print_xchar(f->precision - reslen(number, bas, f), '0', f);
	}
	else if (f->precision > reslen(number, bas, f))
		print_xchar(f->precision - reslen(number, bas, f), '0', f);
	ft_putstr_ret(c, f);
}
