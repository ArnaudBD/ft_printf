#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("printf\n%025.15X\n", -42);
	
	ft_printf("ft_printf\n%025.15X\n", -42);
	return 0;
}