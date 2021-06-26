#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	char	*a01;

	a01 = "Salut";
	printf("printf\nhello, |%7u|\n", 33);
	ft_printf("ft_printf\nhello, |%7u|\n", 33); 


	return 0;
}