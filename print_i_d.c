#include "ft_printf.h"

int	numlen(int number)
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

void	print_xchar(int x, char c)
{
	int	i;

	i = 0;
	while (i < x)
	{
		write(1, &c, 1);
		i++;
	}
	return ;
}

void	print_minus(int number, t_flag *flag)
{
	int j;

	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		j = 1;
	}
	if (flag->precision <= flag->width)
	{
		print_xchar(flag->precision - numlen(number), '0');
		ft_putnbr_fd(number, 1);
		if (flag->precision < numlen(number))
			print_xchar(flag->width - numlen(number) - j, ' ');
		else
			print_xchar(flag->width - flag->precision - j, ' ');
	}
	else if (flag->precision > numlen(number))
	{
		print_xchar(flag->precision - numlen(number), '0');
		ft_putnbr_fd(number, 1);
	}
}

void	print_spaces(int number, t_flag *flag)
{
	int	i;
	int	j;

	i = 0;
	if (number < 0)
		j = 1;
	while ((flag->width - (j + flag->precision)) > i
		&& (flag->width - (j + numlen(number))) > i)
	{
		if (flag->zero == 1 && flag->precision <= 0)
			break ;
		else
			write(1, " ", 1);
		i++;
	}
}

void	print_i_d(int number, t_flag *flag)
{
	int	neg;

	neg = 0;
	if (numlen(number) >= flag->width && numlen(number) >= flag->precision)
		ft_putnbr_fd(number, 1);
	else if (flag->minus == 1)
		print_minus(number, flag);
	else
	{
		print_spaces(number, flag);
		if (number < 0)
		{
			neg = 1;
			write(1, "-", 1);
			number = -number;
		}
		if (flag->zero == 1 && flag->precision <= 0)
			print_xchar((flag->width - (neg + numlen(number))), '0');
		print_xchar(flag->precision - numlen(number), '0');
		if (flag->dot == 1 && flag->precision == 0 && number == 0)
			write(1, " ", 1);
		else
			ft_putnbr_fd(number, 1);
	}
	return ;
}
