#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int	ret;
	int i;

	i = -2147483648;

	ret = printf("|%.*s|", -3, NULL);
	printf("  >> RETURN: %d\n", ret);
	ret = ft_printf("|%.*s|", -3, NULL);
	printf("  >> RETURN: %d\n", ret);
	// ret = printf("|%10.p|", NULL);
	// printf("  >> RETURN: %d\n", ret);
	// ret = ft_printf("|%10.p|", NULL);
	// printf("  >> RETURN: %d\n", ret);

	// ret = printf("|%.*p|", -3, NULL);
	// printf("  >> RETURN: %d\n", ret);
	// ret = ft_printf("|%.*p|", -3, NULL);
	// printf("  << RETURN: %d\n", ret);

	return 0;
}