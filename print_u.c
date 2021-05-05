#include "ft_printf.h"

void	print_u(unsigned int number, t_flag *flag)
{
	if (number < 0)
	{
		number = 4294967295 + number;
			printf("new is : %d\n", number);
	}
	int i;
	int j;

	i = 0;
	j = 0;
	if (numlen(number) >= flag->width && numlen(number) >= flag->precision)
		ft_putnbr_fd(number, 1);
	else if (flag->minus == 1)
	{
		if (number < 0)
		{
			number = 4294967295 + number;
			printf("new is : %d\n", number);
		}
		if (flag->precision <= flag->width)
		{
			while (i < (flag->precision - numlen(number)))
			{
				write(1, "0", 1);
				i++;
			}
			i = 1;
			ft_putnbr_fd(number, 1);
			while ((flag->width - flag->precision) > i)
			{
				write(1, " ", 1);
				i++;
			}
		}
		else if (flag->precision > numlen(number))
		{

			while (i < (flag->precision - numlen(number)))
			{
				write(1, "0", 1);
				i++;
			}
			ft_putnbr_fd(number, 1);
		}
	}
	else
	{
		i = 0;
		if (number < 0)
			j = 1;
		while ((flag->width - (j + flag->precision)) > i && (flag->width - (j + numlen(number))) > i)
		{
			if (flag->zero == 1 && flag->precision == 0)
				break;
			else
				write(1, " ", 1);
			i++;
		}
		if (number < 0)
		{
			number = 4294967295 + number;
			printf("new is : %d\n", number);
		}
		i = 0;
		if (flag->precision > flag->width)
		{
			while (i < (flag->precision - numlen(number)))
			{
				write(1, "0", 1);
				i++;
			}
		}
		else if (flag->zero == 1 && flag->precision == 0)
		{
				while ((flag->width - (j + numlen(number))) > i)
			{
				write(1, "0", 1);
				i++;
			}
		i = 0;
		}
		while (i < (flag->precision - numlen(number)))
			{
				write(1, "0", 1);
				i++;
			}
		if (flag->dot == 1 && flag->precision == 0 && number == 0)
		{
			write(1, " ", 1);
		}
		else
			ft_putnbr_fd(number, 1);
	}
	return;
}