#include "../includes/ft_printf.h"

void	print_percentage(t_flag *flag)
{
	int i;

	i = flag->width;
	if (flag->zero == 1 && flag->minus == 0)
		while(i > 1)
		{
			ft_putchar_ret('0', flag);
			i--;
		}
	else if (flag->minus == 0)
		while(i > 1)
		{
			ft_putchar_ret(' ', flag);
			i--;
		}
	ft_putchar_ret('%', flag);
	if (flag->minus == 1)
	{
		while (i > 1)
		{
			ft_putchar_ret(' ', flag);
			i--;
		}
	}
}