#include "../includes/ft_printf.h"

void	ft_putchar_ret(char c, t_flag *flag)
{
	write(1, &c, 1);
	flag->ret++;
}
