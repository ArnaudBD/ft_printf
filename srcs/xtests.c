#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
	printf("printf\nhello, |%u|\n", 4294967295u);
	
	ft_printf("ft_printf\nhello, |%u|\n", 4294967295u);

	return 0;
}