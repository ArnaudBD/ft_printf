#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	char	*a01;

	a01 = "Salut";
	printf("printf\nhello, |%p|\n", &a01);
	ft_printf("ft_printf\nhello, |%p|\n", &a01); 


	return 0;
}