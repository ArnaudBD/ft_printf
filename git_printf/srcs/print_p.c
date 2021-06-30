#include "../includes/ft_printf.h"

int	reslen_ptr(uintptr_t number, char *base, int dot)
{
	int	i;
	uintptr_t	quo;
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
	return (i);
}

char	*convert_base_ptr(uintptr_t number, char *base, t_flag *flag)
{
	int				i;
	uintptr_t	quo;
	uintptr_t	rem;
	char			*converted;

	i = reslen_ptr(number, base, flag->dot) - 1;
	quo = number / ft_strlen(base);
	rem = number % ft_strlen(base);
	converted = malloc(sizeof(char *) * i + 1);
	if (!converted)
		return (0);
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

void	p_minus_handler(uintptr_t n, t_flag *f, char *base, char *c)
{
	if (f->precision <= f->width)
	{
		print_xchar(f->precision - (2 + reslen_ptr(n, base, f->dot)), '0', f);
		ft_putstr_ret("0x", f);
		ft_putstr_ret(c, f);

		if (f->precision < reslen_ptr(n, base, f->dot))
			print_xchar(f->width - (2 + reslen_ptr(n, base, f->dot)), ' ', f);
		else
			print_xchar(f->width - f->precision - 2, ' ', f);
	}
	else if (f->precision > reslen_ptr(n, base, f->dot))
	{
		print_xchar(f->precision - (2 + reslen_ptr(n, base, f->dot)), '0', f);
		ft_putstr_ret("0x", f);
		ft_putstr_ret(c, f);
	}
	else
	{
		ft_putstr_ret("0x", f);
		ft_putstr_ret(c, f);
	}
}

void	print_p(uintptr_t n, t_flag *f, char *b)
{
	char	*converted;

	converted = convert_base_ptr(n, b, f);
	if (f->minus == 1)
		p_minus_handler(n, f, b, converted);
	else
	{
		if (f->zero == 1 && f->precision < reslen_ptr(n, b, f->dot))
			print_xchar(f->width - reslen_ptr(n, b, f->dot), '0', f);
		else if (f->precision <= f->width)
		{
			if (f->precision < reslen_ptr(n, b, f->dot))
				print_xchar(f->width - reslen_ptr(n, b, f->dot) - 2, ' ', f);
			else
				print_xchar(f->width - f->precision - 2, ' ', f);
			print_xchar(f->precision - reslen_ptr(n, b, f->dot) - 2, '0', f);
		}
		else if (f->precision > reslen_ptr(n, b, f->dot))
			print_xchar(f->precision - reslen_ptr(n, b, f->dot) - 2, '0', f);
		ft_putstr_ret("0x", f);
		ft_putstr_ret(converted, f);
	}
	free(converted);
}








































