#include "../includes/ft_printf.h"
#include <stdio.h>

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
	{
		return (0);
	}
		// return (1 - dot);
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
		{
			print_xchar(flag->width - reslen(n, base, flag), ' ', flag);
		}
		else
			print_xchar(flag->width - flag->precision, ' ', flag);
	}
	else if (flag->precision > reslen(n, base, flag))
	{
		print_xchar(flag->precision - reslen(n, base, flag), '0', flag);
		ft_putstr_ret(conv, flag);
	}
	// else if (n == 0 && flag->precision < 0)
	// 	ft_putchar_ret('0', flag);
	else
		ft_putstr_ret(conv, flag);

}

void	print_x(unsigned int number, t_flag *f, char *base)
{
	char	*converted;

	// if (number == 0 && f->precision == 0 && f->dot == 1)
	// 	return;
	converted = convert_base(number, base, f);
	if (f->minus == 1)
		x_minus_handler(number, converted, f, base);
	else
	{
// 		 if ((f->zero == 1 && f->precision < reslen(number, base, f->dot))
// -                       && f->dot == 0)
// -                       print_xchar(f->width - reslen(number, base, f->dot), '0', f);



		// if ((f->zero == 1 && f->precision != 0 && f->dot == 0))
		if ((f->zero == 1 && f->precision < 0) || (f->zero == 1 && f->dot == 0))
		{
			// write(1, "d", 1);
			// fflush(stdin);
			// printf("width %d", f->width);
			// printf("res %d", reslen(number, base, f));
			if (f->precision < reslen(number, base, f))
				print_xchar(f->width - reslen(number, base, f), '0', f);
			else if (f->precision > 0)
				print_xchar(f->precision - reslen(number, base, f), '0', f);
			// else if (f->width > 0)
			// 	print_xchar(f->width - reslen(number, base, f), ' ', f);
		}
		else if (f->precision <= f->width)
		{
			if (f->precision < reslen(number, base, f))
			{
				// printf("here\n");
				// printf("w %d r %d\n", f->width, reslen(number, base, f->dot));
				// printf("res %d\n", reslen(2, base, f->dot));
				print_xchar(f->width - reslen(number, base, f), ' ', f);
			}
			else
				print_xchar(f->width - f->precision, ' ', f);
			print_xchar(f->precision - reslen(number, base, f), '0', f);
		}
		else if (f->precision > reslen(number, base, f))
		{
			/*printf("precision = %d\n", f->precision);
			printf("reslen = %d\n", reslen(number, base, f->dot));*/
			print_xchar(f->precision - reslen(number, base, f), '0', f);
		}
		// if (number == 0 && f->precision < 0)
		// 	ft_putchar_ret('0', f);
			// printf("%s\n", converted);
		ft_putstr_ret(converted, f);
	}
	if (converted[0] != '0')
		free(converted);
}