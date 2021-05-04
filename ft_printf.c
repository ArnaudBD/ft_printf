#include "ft_printf.h"

int		numlen(int number)
{
	int magnitude;

	magnitude = 0;

	if (number == 0)
		return (1);

	while (number != 0)
	{
		number = number/10;
		magnitude++;
	}
	return (magnitude);
}

void	print_int(int number, t_flag *flag)
{
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

			write(1, "-", 1);
			number = -number;
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

			write(1, "-", 1);
			number = -number;
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


int		ft_printf(const char *str, ...)
{
	int		i;
	t_flag a = {.minus = 0,
				.dot = 0,
				.width = 0,
				.zero = 0,
				.precision = 0};
	t_flag	*flag = &a;
	va_list	ap;
	va_start(ap, str);

	i = 0;

	while(str[i] != 0)
	{
		while (str[i] != '%' && str[i] != 0)
		{
			write(1, &str[i], 1);
			i++;
		}
		if(str[i] == '%' && str[i + 1] == '%')
		{
			write(1, &str[i], 1);
			i++;
		}
		else
		{
			while(str[i] != 'c' && str[i] != 's' && str[i] != 'p'
  				&& str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
				&& str[i] != 'x' && str[i] != 'X' && str[i] != 0)
			{
				if (str[i] == '%')
					i++;
				if (str[i] == '0')
				{
					flag->zero = 1;
					i++;
				}
				if (str[i] == '-')
				{
					flag->minus = 1;
					i++;
				}
				if (str[i] == '*')
				{
					flag->width = va_arg(ap, int);
					i++;
				}
				if (str[i] != '0' && ft_isdigit(str[i]))
				{
					flag->width = ft_atoi(&str[i]);
					i++;
				}
				if (str[i] == '.')
				{
					flag->dot = 1;
					if (ft_isdigit(str[i + 1]))
						flag->precision = ft_atoi(&str[++i]);
					i++;
				}
//				i++;
				while (ft_isdigit(str[i]))
					i++;
			}

		}
		if (str[i] == 'd' || str[i] == 'i') //|| str[i] == 'u')
			print_int(va_arg(ap, int), flag);
		if (str[i] != 0)
			i++;
	}
	return 0;
}