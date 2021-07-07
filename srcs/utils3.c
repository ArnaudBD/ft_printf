/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:50:26 by abiju-du          #+#    #+#             */
/*   Updated: 2021/07/07 09:52:29 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar_ret(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->ret++;
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	int		totalmem;
	char	*str;

	i = 0;
	totalmem = count * size;
	str = malloc(sizeof(char) * totalmem);
	if (str == NULL)
		return (0);
	while (totalmem > 0)
	{
		str[i] = 0;
		i++;
		totalmem--;
	}
	return (str);
}

int	u_numlen(long long int number, t_flag *flag)
{
	int	magnitude;

	if (number == 0 && flag->precision == 0)
		return (0);
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

int	is_flag(const char *str, int i)
{
	if (str[i] != '%' && str[i] != 'c' && str[i] != 's' && str[i] != 'p'
		&& str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
		&& str[i] != 'x' && str[i] != 'X' && str[i] != 0 && str[i] != '*'
		&& str[i] != '0' && str[i] != '.'
		&& !ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
		return (++i);
	return (i);
}

void	not_m_but_dot_handler(t_counters *countr, int l, const char *s, t_flag *f)
{
	countr->j = -1;
	while (countr->j++ >= -1 && f->width != 0 && (((f->precision < 0
					&& (f->width - (countr->j + l) > 0)))
			|| (f->precision >= 0 && (f->width - (countr->j + l) > 0
					|| (f->width != 0
						&& f->width - (countr->j + f->precision) > 0)))))
		ft_putchar_ret(' ', f);
	if (s == NULL)
		countr->k = null_handler(countr, f);
	else
		while (f->precision-- != 0 && s[countr->i] != 0)
			ft_putchar_ret(s[countr->i++], f);
}
