#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("printf\n%x\n", -42);
	
	ft_printf("ft_printf\n%x\n", -42);
	return 0;
}