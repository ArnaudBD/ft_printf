#include "ft_printf.h"

void		print_x(int nbr, t_flag *flag)
{
	int		i;
	int		j;
	int		quo;
	int		rem;
	char	base[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = 0;
	j = 0;
	quo = nbr / 16;
	rem = nbr % 16;

	while (quo != 0)
	{
		rem = quo % 16;
		quo = quo / 16;
		i++;
	}
	quo = nbr / 16;
	rem = nbr % 16;

	while (i >= 0)
	{
		while (j < i)
		{
		rem = quo % 16;
		quo = quo / 16;
		j++;
		}
		write(1, &base[rem], 1);
		i--;
		j = 0;
		quo = nbr / 16;
		rem = nbr % 16;
	}


	return ;
}