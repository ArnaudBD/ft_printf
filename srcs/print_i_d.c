#include "../includes/ft_printf.h"

void	print_xchar(int x, char c, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_putchar_ret(c, flag);
		i++;
	}
	return ;
}

void	print_minus(long long int number, t_flag *flag)
{
	int	j;

	j = 0;
	if (number < 0)
	{
		ft_putchar_ret('-', flag);
		number = -number;
		j = 1;
	}
	print_xchar(flag->precision - numlen(number), '0', flag);
	if (flag->precision <= flag->width)
	{
		if (flag->dot != 1 || flag->precision != 0 || number != 0)
			ft_putnbr_ret(number, flag);
		else
			ft_putchar_ret(' ', flag);
		if (flag->precision < numlen(number))
			print_xchar(flag->width - numlen(number) - j, ' ', flag);
		else
			print_xchar(flag->width - flag->precision - j, ' ', flag);
	}
	else if (flag->precision > numlen(number))
		ft_putnbr_ret(number, flag);
}

void	print_spaces(int number, t_flag *flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (number < 0)
		j = 1;
	if ((flag->width == numlen(number)) && flag->dot == 1 && number == 0
		&& flag->precision == 0)
		ft_putchar_ret(' ', flag);
	while ((flag->width - (j + flag->precision)) > i
		&& (flag->width - (j + numlen(number))) > i)
	{
		if (flag->zero == 1 && ((flag->dot == 0 && flag->precision <= 0)
				|| flag->precision < 0))
			break ;
		else
			ft_putchar_ret(' ', flag);
		i++;
	}
}

int	neg_handler(int *number, int neg, t_flag *flag)
{
	int	n;

	n = *number;
	if (n < 0 && n != -2147483648)
	{
		neg = 1;
		ft_putchar_ret('-', flag);
		*number = -n;
	}
	return (neg);
}

void	print_i_d(int number, t_flag *flag)
{
	int	neg;

	neg = 0;
	if (numlen(number) >= flag->width && numlen(number) >= flag->precision
		&& (flag->dot == 0 && number != 0))
		ft_putnbr_ret(number, flag);
	else if (flag->minus == 1)
		print_minus(number, flag);
	else
	{
		print_spaces(number, flag);
		neg = neg_handler(&number, neg, flag);
		if (flag->zero == 1 && ((flag->dot == 0 && flag->precision <= 0)
				|| flag->precision < 0))
			print_xchar((flag->width - (neg + numlen(number))), '0', flag);
		print_xchar(flag->precision - numlen(number), '0', flag);
		if ((flag->dot == 1 && flag->precision == 0 && number == 0)
			&& (numlen(number) < flag->width
				|| numlen(number) < flag->precision))
			ft_putchar_ret(' ', flag);
		else if (flag->dot != 1 || flag->precision != 0 || number != 0)
			ft_putnbr_ret(number, flag);
	}
	return ;
}
