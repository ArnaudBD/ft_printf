#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int	ret;
	int i;

	i = -2147483648;

	ret = printf("|%1.1d|", 0);
	printf("  >> RETURN: %d\n", ret);
	ret = ft_printf("|%1.1d|",0);
	printf("  << RETURN: %d\n", ret);

	return 0;
}