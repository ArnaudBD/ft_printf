#include "ft_printf.h"

void		print_x(int nbr, t_flag *flag)
{
	int		i;
	int		j;
	int		div;
	int		quo;
	char	base[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = 1;
	j = 0;
	div = nbr / 16;
	quo = nbr % 16;

	while (div != 0)
	{
		div = quo / 16;
		quo = quo % 16;
		i++;
	}
	div = nbr / 16;
	quo = nbr % 16;

printf(" i = %d\n", i);
printf(" div = %d\n", div);
printf(" quo = %d\n", quo);

	while (i != 0)
	{
		while (j <= i)
		{
printf("-----------in the loop-----------------\n");
printf(" i = %d\n", i);
printf(" j = %d\n", j);
printf(" div = %d\n", div);
printf(" quo = %d\n", quo);

		div = quo / 16;
		quo = quo % 16;
		j++;
printf("-----------end of the loop-----------------\n");
printf(" i = %d\n", i);
printf(" j = %d\n", j);
printf(" div = %d\n", div);
printf(" quo = %d\n", quo);
		}
printf("------------out the loop----------------\n");
printf(" i = %d\n", i);
printf(" j = %d\n", j);
printf(" div = %d\n", div);
printf(" quo = %d\n", quo);

printf("----------------------------\n");
		write(1, &base[quo], 1);
printf("\n----------------------------\n");
		i--;
		j = 0;
		div = nbr / 16;
		quo = nbr % 16;
printf("---------end of while-------------------\n");
printf(" i = %d\n", i);
printf(" div = %d\n", div);
printf(" quo = %d\n", quo);


	}


	return ;
}