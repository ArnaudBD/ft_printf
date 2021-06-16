#include "../includes/ft_printf.h"

void	print_percentage(t_flag *flag)
{
	int i;

	i = flag->width;
	if (flag->zero == 1 && flag->minus == 0)
		while(i > 1)
		{
			write(1, "0", 1);
			i--;
		}
	else if (flag->minus == 0)
		while(i > 1)
		{
			write(1, " ", 1);
			i--;
		}
	write(1, "%", 1);
	if (flag->minus == 1)
	{
		while (i > 1)
		{
			write(1, " ", 1);
			i--;
		}
	}
}