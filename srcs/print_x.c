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

int	reslen(unsigned int number, char *base, int dot)
{
	int	i;
	int	quo;
	int	rem;

	if (number == 0)
		return (1 - dot);
	i = 1;
	quo = number / ft_strlen(base);
	rem = number % ft_strlen(base);
	while (quo != 0)
	{
		rem = quo % ft_strlen(base);
		quo = quo / ft_strlen(base);
		i++;
	}
printf("i = %d\n", i);
	return (i);
}

char	*convert_base(unsigned int number, char *base, t_flag *flag)
{
	int		i;
	int		quo;
	int		rem;
	char	*converted;

	converted = NULL;
	i = reslen(number, base, flag->dot) - 1;
	quo = number / ft_strlen(base);
	rem = number % ft_strlen(base);
	if (i < 0)
	{
		printf("i = %d\n", i);
		return ("0");
	}
	else if (i > 0)
		converted = malloc(sizeof(char *) * i + 1);
	if (!converted)
		return ("0");
	else
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
		print_xchar(flag->precision - reslen(n, base, flag->dot), '0', flag);
		ft_putstr_ret(conv, flag);
		if (flag->precision < reslen(n, base, flag->dot))
			print_xchar(flag->width - reslen(n, base, flag->dot), ' ', flag);
		else
			print_xchar(flag->width - flag->precision, ' ', flag);
	}
	else if (flag->precision > reslen(n, base, flag->dot))
	{
		print_xchar(flag->precision - reslen(n, base, flag->dot), '0', flag);
		ft_putstr_ret(conv, flag);
	}
	else
		ft_putstr_ret(conv, flag);
}

void	print_x(unsigned int number, t_flag *f, char *base)
{
	char	*converted;

	/*if (f->precision < 0)
		f->precision = -f->precision;*/
	converted = convert_base(number, base, f);
	if (f->minus == 1)
		x_minus_handler(number, converted, f, base);
	else
	{
		if ((f->zero == 1 && f->precision < reslen(number, base, f->dot))
			&& f->dot == 0)
			print_xchar(f->width - reslen(number, base, f->dot), '0', f);
		else if (f->precision <= f->width)
		{
			if (f->precision < reslen(number, base, f->dot))
				print_xchar(f->width - reslen(number, base, f->dot), ' ', f);
			else
				print_xchar(f->width - f->precision, ' ', f);
			print_xchar(f->precision - reslen(number, base, f->dot), '0', f);
		}
		else if (f->precision > reslen(number, base, f->dot))
		{
			/*printf("precision = %d\n", f->precision);
			printf("reslen = %d\n", reslen(number, base, f->dot));*/
			print_xchar(f->precision - reslen(number, base, f->dot), '0', f);
		}
		ft_putstr_ret(converted, f);
	}
	if (converted[0] != '0')
		free(converted);
}
