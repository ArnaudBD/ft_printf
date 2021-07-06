#include "../includes/ft_printf.h"

int	star_handler(int i, t_flag *flag, va_list *ap)
{
	if (flag->dot == 0)
		flag->width = va_arg(*ap, int);
	else
		flag->precision = va_arg(*ap, int);
	if (flag->width < 0 && flag->precision >= 0)
	{
		flag->minus = 1;
		flag->width = -flag->width;
	}
	i++;
	return (i);
}

int	dot_handler(const char *str, int i, t_flag *flag)
{
	if (str[i] == '-' && flag->dot == 0)
	{
		flag->minus = 1;
		i++;
	}
	return (i);
}

int	flag_organizer(const char *str, int i, t_flag *flag, va_list *ap)
{
	while (str[i] != '%' && str[i] != 'c' && str[i] != 's' && str[i] != 'p'
		&& str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
		&& str[i] != 'x' && str[i] != 'X' && str[i] != 0)
	{
		while (str[i] == ' ')
			i++;
		i = dot_handler(str, i, flag);
		if (str[i] == '0')
			flag->zero = 1;
		if (ft_isdigit(str[i]))
			flag->width = ft_atoi(&str[i++]);
		else if (str[i] == '*')
			i = star_handler(i, flag, ap);
		else if (str[i] == '.')
		{
			flag->dot = 1;
			if (ft_isdigit(str[i + 1]))
				flag->precision = ft_atoi(&str[++i]);
			i++;
		}
		while (ft_isdigit(str[i]))
			i++;
		i = is_flag(str, i);
	}
	return (i);
}

void	arg_printer(const char *str, va_list *ap, int i, t_flag *flag)
{
	if (str[i] == 'd' || str[i] == 'i')
		print_i_d(va_arg(*ap, int), flag);
	else if (str[i] == 'u')
		print_u(va_arg(*ap, unsigned int), flag);
	else if (str[i] == 's')
		print_s(va_arg(*ap, char *), flag);
	else if (str[i] == 'c')
		print_c(va_arg(*ap, const void *), flag);
	else if (str[i] == 'x')
		print_x(va_arg(*ap, unsigned int), flag, "0123456789abcdef");
	else if (str[i] == 'X')
		print_x(va_arg(*ap, unsigned int), flag, "0123456789ABCDEF");
	else if (str[i] == 'p')
		print_p(va_arg(*ap, long unsigned int), flag, "0123456789abcdef");
	else if (str[i] == '%')
		print_percentage(flag);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_flag	a;
	t_flag	*flag;
	va_list	ap;

	flag = &a;
	flag_initializer(&a);
	a.ret = 0;
	va_start(ap, str);
	i = 0;
	while (str[i] != 0)
	{
		while (str[i] != '%' && str[i] != 0)
			ft_putchar_ret(str[i++], flag);
		if (str[i] == '%')
			i = flag_organizer(str, ++i, flag, &ap);
		arg_printer(str, &ap, i, flag);
		if (str[i] != 0)
			i++;
		flag_initializer(&a);
	}
	va_end(ap);
	return (flag->ret);
}
