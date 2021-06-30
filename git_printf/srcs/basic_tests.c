#include "ft_printf.h"

int	main()
{
	char	*str = "Salut !";
	int		*ptr;
	int		num;
	char	type;

	type = 'i';
	num = -123;
	ptr = &num;

//	printf("%.5i\n", *ptr);

	printf("%1.0s\n", str);
	printf("%1.1s\n", str);
	printf("%1.2s\n", str);
	printf("%1.3s\n", str);
	printf("%1.4s\n", str);
	printf("%1.5s\n", str);
	printf("%1.6s\n", str);
	printf("%1.7s\n", str);
	printf("%1.8s\n", str);
	printf("%1.9s\n", str);
	printf("%1.10s\n--1\n", str);

	ft_printf("%1.0s\n", str);
	ft_printf("%1.1s\n", str);
	ft_printf("%1.2s\n", str);
	ft_printf("%1.3s\n", str);
	ft_printf("%1.4s\n", str);
	ft_printf("%1.5s\n", str);
	ft_printf("%1.6s\n", str);
	ft_printf("%1.7s\n", str);
	ft_printf("%1.8s\n", str);
	ft_printf("%1.9s\n", str);
	ft_printf("%1.10s\n-----------------\n", str);
	

	printf("%0s\n", str);
	printf("%1s\n", str);
	printf("%2s\n", str);
	printf("%3s\n", str);
	printf("%4s\n", str);
	printf("%5s\n", str);
	printf("%6s\n", str);
	printf("%7s\n", str);
	printf("%8s\n", str);
	printf("%9s\n", str);
	printf("%10s\n--2\n", str);

	ft_printf("%0s\n", str);
	ft_printf("%1s\n", str);
	ft_printf("%2s\n", str);
	ft_printf("%3s\n", str);
	ft_printf("%4s\n", str);
	ft_printf("%5s\n", str);
	ft_printf("%6s\n", str);
	ft_printf("%7s\n", str);
	ft_printf("%8s\n", str);
	ft_printf("%9s\n", str);
	ft_printf("%10s\n-----------------\n", str);


	printf("%10.0s\n", str);
	printf("%10.1s\n", str);
	printf("%10.2s\n", str);
	printf("%10.3s\n", str);
	printf("%10.4s\n", str);
	printf("%10.5s\n", str);
	printf("%10.6s\n", str);
	printf("%10.7s\n", str);
	printf("%10.8s\n", str);
	printf("%10.9s\n", str);
	printf("%10.10s\n--3\n", str);
	
	ft_printf("%10.0s\n", str);
	ft_printf("%10.1s\n", str);
	ft_printf("%10.2s\n", str);
	ft_printf("%10.3s\n", str);
	ft_printf("%10.4s\n", str);
	ft_printf("%10.5s\n", str);
	ft_printf("%10.6s\n", str);
	ft_printf("%10.7s\n", str);
	ft_printf("%10.8s\n", str);
	ft_printf("%10.9s\n", str);
	ft_printf("%10.10s\n-----------------\n", str);


	printf("%-10.0s\n", str);
	printf("%-10.1s\n", str);
	printf("%-10.2s\n", str);
	printf("%-10.3s\n", str);
	printf("%-10.4s\n", str);
	printf("%-10.5s\n", str);
	printf("%-10.6s\n", str);
	printf("%-10.7s\n", str);
	printf("%-10.8s\n", str);
	printf("%-10.9s\n", str);
	printf("%-10.10s\n--4\n", str);

	ft_printf("%-10.0s\n", str);
	ft_printf("%-10.1s\n", str);
	ft_printf("%-10.2s\n", str);
	ft_printf("%-10.3s\n", str);
	ft_printf("%-10.4s\n", str);
	ft_printf("%-10.5s\n", str);
	ft_printf("%-10.6s\n", str);
	ft_printf("%-10.7s\n", str);
	ft_printf("%-10.8s\n", str);
	ft_printf("%-10.9s\n", str);
	ft_printf("%-10.10s\n-----------------\n", str);

	
	printf("%-1s\n", str);
	printf("%-2s\n", str);
	printf("%-3s\n", str);
	printf("%-4s\n", str);
	printf("%-5s\n", str);
	printf("%-6s\n", str);
	printf("%-7s\n", str);
	printf("%-8s\n", str);
	printf("%-9s\n", str);
	printf("%-10s\n--5\n", str);

	ft_printf("%-1s\n", str);
	ft_printf("%-2s\n", str);
	ft_printf("%-3s\n", str);
	ft_printf("%-4s\n", str);
	ft_printf("%-5s\n", str);
	ft_printf("%-6s\n", str);
	ft_printf("%-7s\n", str);
	ft_printf("%-8s\n", str);
	ft_printf("%-9s\n", str);
	ft_printf("%-10s\n-----------------\n", str);


	return (0);
}