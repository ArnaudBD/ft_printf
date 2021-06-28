#include "../includes/ft_printf.h"

void	print_u(unsigned int number, t_flag *flag)
{
	// if (number < 0)
	// {
	// 	number = 4294967295 + number;
	// 		printf("new is : %d\n", number);
	// }
	int i;
	int j;

	i = 0;
	j = 0;
	if (numlen(number) >= flag->width && numlen(number) >= flag->precision && (flag->dot != 1 || flag->precision != 0 || number != 0))
			ft_putnbr_ret(number, flag);
	else if (flag->minus == 1)
	{
		// if (number < 0)
		// {
		// 	number = 4294967295 + number;
		// 	printf("new is : %d\n", number);
		// }
		if (flag->precision <= flag->width)
		{
			while (i < (flag->precision - numlen(number)))
			{
				ft_putchar_ret('0', flag);
				i++;
			}
			if (i != 0)
				j = flag->precision;
			else if (flag->dot != 1 || flag->precision != 0 || number != 0)
				j = numlen(number);
			i = 0;
			if (flag->dot != 1 || flag->precision != 0 || number != 0)
				ft_putnbr_ret(number, flag);
			while ((flag->width - j) > i)
			{
				ft_putchar_ret(' ', flag);
				i++;
			}
		}
		else if (flag->precision > numlen(number))
		{

			while (i < (flag->precision - numlen(number)))
			{
				ft_putchar_ret('0', flag);
				i++;
			}
			if (flag->dot != 1 || flag->precision != 0 || number != 0)
				ft_putnbr_ret(number, flag);
		}
	}
	else
	{
		i = 0;
		if (number < 0)
			j = 1;
		while ((flag->width - (j + flag->precision)) > i && (flag->width - (j + numlen(number))) > i)
		{
			if (flag->zero == 1 && flag->dot == 0)
				break;
			else
				ft_putchar_ret(' ', flag);
			i++;
		}
		// if (number < 0)
		// {
		// 	number = 4294967295 + number;
		// 	printf("new is : %d\n", number);
		// }
		i = 0;
		if (flag->precision > flag->width)
		{
			while (i < (flag->precision - numlen(number)))
			{
				ft_putchar_ret('0', flag);
				i++;
			}
		}
		else if (flag->zero == 1 && flag->dot == 0)
		{
				while ((flag->width - (j + numlen(number))) > i)
			{
				ft_putchar_ret('0', flag);
				i++;
			}
		i = 0;
		}
		while (i < (flag->precision - numlen(number)))
			{
				ft_putchar_ret('0', flag);
				i++;
			}
		if (flag->dot == 1 && flag->precision == 0 && number == 0 && (numlen(number) <= flag->width || numlen(number) < flag->precision))
		{
			ft_putchar_ret(' ', flag);
		}
		else if (flag->dot != 1 || flag->precision != 0 || number != 0)
			ft_putnbr_ret(number, flag);
	}
	return ;
}
