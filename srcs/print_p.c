#include "../includes/ft_printf.h"


char	*convert_base_ptr(uintptr_t number, char *base, t_flag *flag)
{
	int				i;
	uintptr_t		quo;
	uintptr_t		rem;
	char			*converted;

	i = reslen(number, base, flag->dot) - 1;
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

int	reslen_ptr(uintptr_t number, char *base, int dot)
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
	return (i);
}

void	print_p(uintptr_t number, t_flag *flag, char *base)
{
	char	*converted;

	converted = convert_base_ptr(number, base, flag);
	if (flag->minus == 1)
		{
			if (flag->precision <= flag->width)
			{
				print_xchar(flag->precision - (2 + reslen_ptr(number, base, flag->dot)), '0', flag);
				ft_putstr_ret("0x", flag);
				ft_putstr_ret(converted, flag);

				if (flag->precision < reslen_ptr(number, base, flag->dot))
					print_xchar(flag->width - (2 + reslen_ptr(number, base, flag->dot)), ' ', flag);
				else
					print_xchar(flag->width - flag->precision, ' ', flag);
			}
			else if (flag->precision > reslen_ptr(number, base, flag->dot))
			{
				print_xchar(flag->precision - (2 + reslen_ptr(number, base, flag->dot)), '0', flag);
				ft_putstr_ret("0x", flag);
				ft_putstr_ret(converted, flag);
			}
			else
			{
				ft_putstr_ret("0x", flag);
				ft_putstr_ret(converted, flag);
			}
		}
	else
	{
		if (flag->zero == 1 && flag->precision < reslen_ptr(number, base, flag->dot))
			print_xchar(flag->width - reslen_ptr(number, base, flag->dot), '0', flag);
		else if (flag->precision <= flag->width)
			{
				if (flag->precision < reslen_ptr(number, base, flag->dot))
					print_xchar(flag->width - reslen_ptr(number, base, flag->dot) - 2, ' ', flag);
				else
					print_xchar(flag->width - flag->precision, ' ', flag);
				print_xchar(flag->precision - reslen_ptr(number, base, flag->dot) - 2, '0', flag);
			}
		else if (flag->precision > reslen_ptr(number, base, flag->dot))
		{
			print_xchar(flag->precision - reslen_ptr(number, base, flag->dot) - 2, '0', flag);
		}
			ft_putstr_ret("0x", flag);
			ft_putstr_ret(converted, flag);
	}
	free(converted);
}








































