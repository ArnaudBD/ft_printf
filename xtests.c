#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("printf\n%-50.10i\n", 1981621);
	
	ft_printf("ft_printf\n%-50.10i\n", 1981621);
	return 0;
}