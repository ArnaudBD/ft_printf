#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int	ret;
	int i;

	i = -2147483648;

	// ret = printf("13 > yeyeye%*iyeyeye%05.*d", -5, 42, -15, 42);
	// printf("  >> RETURN: %d\n", ret);
	// ret = ft_printf("13 < yeyeye%*iyeyeye%05.*d", -5, 42, -15, 42);
	// printf("  << RETURN: %d\n", ret);

	// ret = printf("14 > yeyeye%d%d%dyeyeye", 1, -2, 3);
	// printf("  >> RETURN: %d\n", ret);
	// ret = ft_printf("14 < yeyeye%d%d%dyeyeye", 1, -2, 3);
	// printf("  << RETURN: %d\n", ret);

	ret = printf("15 > |%32s|", NULL);
	printf("  >> RETURN: %d\n", ret);
	ret = ft_printf("15 < |%32s|", NULL);
	printf("  << RETURN: %d\n", ret);

	// ret = printf("16 > %15.*dyeyeye%2.*dyeyeye", -2, -123456789, -2, 8);
	// printf("  >> RETURN: %d\n", ret);
	// ret = ft_printf("16 < %15.*dyeyeye%2.*dyeyeye", -2, -123456789, -2, 8);
	// printf("  << RETURN: %d\n", ret);


	return 0;
}