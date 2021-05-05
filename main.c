#include "ft_printf.h"

int main()
{

	write(1, "1\n", 2);
	printf("un %% int %-*.5s\n", 3, "Salut!");
	ft_printf("un %% int %-*.5s\n\n\n", 3, "Salut!");
	
	write(1, "2\n", 2);
	printf("un %% int %0*.5s\n", 3, "Salut!");
	ft_printf("un %% int %0*.5s\n\n\n", 3, "Salut!");
	
	write(1, "3\n", 2);
	printf("un %% int %-*.3s\n", 5, "Salut!");
	ft_printf("un %% int %-*.3s\n\n\n", 5, "Salut!");
	
	write(1, "4\n", 2);
	printf("un %% int %0*.3s\n", 5, "Salut!");
	ft_printf("un %% int %0*.3s\n\n\n", 5, "Salut!");
	
	write(1, "5\n", 2);
	printf("un %% int %.5s\n", "Salut!");
	ft_printf("un %% int %.5s\n\n\n", "Salut!");
	
	write(1, "6\n", 2);
	printf("un %% int %5s\n", "Salut!");
	ft_printf("un %% int %5s\n\n\n", "Salut!");

	write(1, "7\n", 2);
	printf("un %% int %5.s\n", "Salut!");
	ft_printf("un %% int %5.s\n\n\n", "Salut!");

	write(1, "8\n", 2);
	printf("un %% int %-5s\n", "Salut!");
	ft_printf("un %% int %-5s\n\n\n", "Salut!");

	write(1, "9\n", 2);
	printf("un %% int %05s\n", "Salut!");
	ft_printf("un %% int %05s\n\n\n", "Salut!");

	write(1, "10\n", 3);
	printf("un %% int %s\n", "Salut!");
	ft_printf("un %% int %s\n\n\n", "Salut!");
/*
	write(1, "11\n", 3);
	printf("un %% int %-*.5s\n", 3, 22);
	ft_printf("un %% int %-*.5s\n\n\n", 3, 22);
	
	write(1, "12\n", 3);
	printf("un %% int %0*.5s\n", 3, 22);
	ft_printf("un %% int %0*.5s\n\n\n", 3, 22);
	
	write(1, "13\n", 3);
	printf("un %% int %-*.3s\n", 5, 22);
	ft_printf("un %% int %-*.3s\n\n\n", 5, 22);
	
	write(1, "14\n", 3);
	printf("un %% int %0*.3s\n", 5, 22);
	ft_printf("un %% int %0*.3s\n\n\n", 5, 22);
	
	write(1, "15\n", 3);
	printf("un %% int %.5s\n", 22);
	ft_printf("un %% int %.5s\n\n\n", 22);
	
	write(1, "16\n", 3);
	printf("un %% int %5s\n", 22);
	ft_printf("un %% int %5s\n\n\n", 22);

	write(1, "17\n", 3);
	printf("un %% int %5.s\n", 22);
	ft_printf("un %% int %5.s\n\n\n", 22);

	write(1, "18\n", 3);
	printf("un %% int %-5s\n", 22);
	ft_printf("un %% int %-5s\n\n\n", 22);

	write(1, "19\n", 3);
	printf("un %% int %05s\n", 22);
	ft_printf("un %% int %05s\n\n\n", 22);

	write(1, "20\n", 3);
	printf("un %% int %s\n", 222);
	ft_printf("un %% int %s\n\n\n", 222);

		write(1, "21\n", 3);
	printf("un %% int %-*.5s\n", 0, 0);
	ft_printf("un %% int %-*.5s\n\n\n", 0, 0);
	
	write(1, "22\n", 3);
	printf("un %% int %0*.5s\n", 0, 0);
	ft_printf("un %% int %0*.5s\n\n\n", 3, 0);
	
	write(1, "23\n", 3);
	printf("un %% int %-*.3s\n", 0, 0);
	ft_printf("un %% int %-*.3s\n\n\n", 0, 0);
	
	write(1, "24\n", 3);
	printf("un %% int %0*.3s\n", 0, 0);
	ft_printf("un %% int %0*.3s\n\n\n", 0, 0);
	
	write(1, "25\n", 3);
	printf("un %% int %.5s\n", 0);
	ft_printf("un %% int %.5s\n\n\n", 0);
	
	write(1, "26\n", 3);
	printf("un %% int %5s\n", 0);
	ft_printf("un %% int %5s\n\n\n", 0);

	write(1, "27\n", 3);
	printf("un %% int %5.s\n", 0);
	ft_printf("un %% int %5.s\n\n\n", 0);

	write(1, "28\n", 3);
	printf("un %% int %-5s\n", 0);
	ft_printf("un %% int %-5s\n\n\n", 0);

	write(1, "29\n", 3);
	printf("un %% int %05s\n", 0);
	ft_printf("un %% int %05s\n\n\n", 0);

	write(1, "30\n", 3);
	printf("un %% int %s\n", 0);
	ft_printf("un %% int %s\n\n\n", 0);
*/	
	return 0;
}
