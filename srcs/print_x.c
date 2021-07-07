/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:50:05 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:52:23 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_ret(char *s, t_flag *flag)
{
	int	i;

	if (s == 0 && flag->dot == 1 && flag->precision < 0)
		ft_putchar_ret('0', flag);
	if (s == 0)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		ft_putchar_ret(s[i], flag);
		i++;
	}
}

int	reslen(unsigned int number, char *base, t_flag *flag)
{
	int	i;
	int	quo;
	int	rem;

	if (number == 0 && flag->precision != 0)
		return (1);
	else if (number == 0 && flag->precision == 0 && flag->dot == 1)
		return (0);
	i = 1;
	quo = number / ft_strlen(base);
	rem = number % ft_strlen(base);
	while (quo != 0)
	{
		rem = quo % ft_strlen(base);
		quo = quo / ft_strlen(base);
		i++;
	}
	return (i);
}

char	*convert_base(unsigned int number, char *base, t_flag *flag)
{
	int		i;
	int		quo;
	int		rem;
	char	*converted;

	converted = calloc(sizeof(char), 100);
	if (converted == NULL)
		return (NULL);
	i = reslen(number, base, flag) - 1;
	quo = number / ft_strlen(base);
	rem = number % ft_strlen(base);
	converted[i + 1] = 0;
	while (i >= 0)
	{
		converted[i] = base[rem];
		rem = quo % ft_strlen(base);
		quo = quo / ft_strlen(base);
		i--;
	}
	return (converted);
}

void	x_minus_handler(unsigned int n, char *conv, t_flag *flag, char *base)
{
	if (flag->precision <= flag->width)
	{
		print_xchar(flag->precision - reslen(n, base, flag), '0', flag);
		ft_putstr_ret(conv, flag);
		if (flag->precision < reslen(n, base, flag))
			print_xchar(flag->width - reslen(n, base, flag), ' ', flag);
		else
			print_xchar(flag->width - flag->precision, ' ', flag);
	}
	else if (flag->precision > reslen(n, base, flag))
	{
		print_xchar(flag->precision - reslen(n, base, flag), '0', flag);
		ft_putstr_ret(conv, flag);
	}
	else
		ft_putstr_ret(conv, flag);
}

void	print_x(unsigned int number, t_flag *f, char *base)
{
	char	*converted;

	converted = convert_base(number, base, f);
	if (f->minus == 1)
		x_minus_handler(number, converted, f, base);
	else
		x_not_minus_handler(number, converted, f, base);
	if (converted[0] != '0')
		free(converted);
}
