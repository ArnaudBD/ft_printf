#include "ft_printf.h"

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
		if (str[i] == 'd' || str[i] == 'i')
			print_i_d(va_arg(ap, int), flag);
		// else if (str[i] == 'u')
		// 	print_u(va_arg(ap, unsigned int), flag);
		else if (str[i] == 's')
			print_s(va_arg(ap, char *), flag);
		if (str[i] != 0)
			i++;
	}
	return 0;
}