#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
	printf("printf\nhello, %32s.|\n", NULL);
	
	ft_printf("ft_printf\nhello, %32s.|\n", NULL);

	return 0;
}