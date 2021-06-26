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
				print_xchar(flag->precision - (2 + reslen_ptr(number, base, flag->dot)), '0');
				write(1, "0x", 2);
				ft_putstr_fd(converted, 1);

				if (flag->precision < reslen_ptr(number, base, flag->dot))
					print_xchar(flag->width - (2 + reslen_ptr(number, base, flag->dot)), ' ');
				else
					print_xchar(flag->width - flag->precision, ' ');
			}
			else if (flag->precision > reslen_ptr(number, base, flag->dot))
			{
				print_xchar(flag->precision - (2 + reslen_ptr(number, base, flag->dot)), '0');
				write(1, "0x", 2);
				ft_putstr_fd(converted, 1);
			}
			else
			{
				write(1, "0x", 2);
				ft_putstr_fd(converted, 1);
			}
		}
	else
	{
		if (flag->zero == 1 && flag->precision < reslen_ptr(number, base, flag->dot))
			print_xchar(flag->width - reslen_ptr(number, base, flag->dot), '0');
		else if (flag->precision <= flag->width)
			{
				if (flag->precision < reslen_ptr(number, base, flag->dot))
					print_xchar(flag->width - reslen_ptr(number, base, flag->dot) - 2, ' ');
				else
					print_xchar(flag->width - flag->precision, ' ');
				print_xchar(flag->precision - reslen_ptr(number, base, flag->dot) - 2, '0');
			}
		else if (flag->precision > reslen_ptr(number, base, flag->dot))
		{
			print_xchar(flag->precision - reslen_ptr(number, base, flag->dot) - 2, '0');
		}
			write(1, "0x", 2);
			ft_putstr_fd(converted, 1);
	}
	free(converted);
}








































