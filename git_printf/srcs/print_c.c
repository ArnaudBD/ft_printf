#include "../includes/ft_printf.h"

void	print_c(const void *c, t_flag *flag)
{
	if (flag->minus == 1)
	{
		write(1, &c, 1);
		flag->ret++;
	}
	while (flag->width > 1)
	{
		write(1, " ", 1);
		flag->width--;
		flag->ret++;
	}
	if (flag->minus == 0)
	{
		write(1, &c, 1);
		flag->ret++;
	}
	return ;
}