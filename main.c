#include "ft_printf.h"

int main()
{
	write(1, "1\n", 2);
	printf("un %% int %-*.5d\n", 3, -1);
	ft_printf("un %% int %-*.5d\n\n\n", 3, -1);
	
	write(1, "2\n", 2);
	printf("un %% int %0*.5d\n", 3, -1);
	ft_printf("un %% int %0*.5d\n\n\n", 3, -1);
	
	write(1, "3\n", 2);
	printf("un %% int %-*.3d\n", 5, -1);
	ft_printf("un %% int %-*.3d\n\n\n", 5, -1);
	
	write(1, "4\n", 2);
	printf("un %% int %0*.3d\n", 5, -1);
	ft_printf("un %% int %0*.3d\n\n\n", 5, -1);
	
	write(1, "5\n", 2);
	printf("un %% int %.5d\n", -1);
	ft_printf("un %% int %.5d\n\n\n", -1);
	
	write(1, "6\n", 2);
	printf("un %% int %5d\n", -1);
	ft_printf("un %% int %5d\n\n\n", -1);

	write(1, "7\n", 2);
	printf("un %% int %5.d\n", -1);
	ft_printf("un %% int %5.d\n\n\n", -1);

	write(1, "8\n", 2);
	printf("un %% int %-5d\n", -1);
	ft_printf("un %% int %-5d\n\n\n", -1);

	write(1, "9\n", 2);
	printf("un %% int %05d\n", -1);
	ft_printf("un %% int %05d\n\n\n", -1);

	write(1, "10\n", 3);
	printf("un %% int %d\n", -1);
	ft_printf("un %% int %d\n\n\n", -1);

	write(1, "11\n", 3);
	printf("un %% int %-*.5d\n", 3, 222);
	ft_printf("un %% int %-*.5d\n\n\n", 3, 222);
	
	write(1, "12\n", 3);
	printf("un %% int %0*.5d\n", 3, 222);
	ft_printf("un %% int %0*.5d\n\n\n", 3, 222);
	
	write(1, "13\n", 3);
	printf("un %% int %-*.3d\n", 5, 222);
	ft_printf("un %% int %-*.3d\n\n\n", 5, 222);
	
	write(1, "14\n", 3);
	printf("un %% int %0*.3d\n", 5, 222);
	ft_printf("un %% int %0*.3d\n\n\n", 5, 222);
	
	write(1, "15\n", 3);
	printf("un %% int %.5d\n", 222);
	ft_printf("un %% int %.5d\n\n\n", 222);
	
	write(1, "16\n", 3);
	printf("un %% int %5d\n", 222);
	ft_printf("un %% int %5d\n\n\n", 222);

	write(1, "17\n", 3);
	printf("un %% int %5.d\n", 222);
	ft_printf("un %% int %5.d\n\n\n", 222);

	write(1, "18\n", 3);
	printf("un %% int %-5d\n", 222);
	ft_printf("un %% int %-5d\n\n\n", 222);

	write(1, "19\n", 3);
	printf("un %% int %05d\n", 222);
	ft_printf("un %% int %05d\n\n\n", 222);

	write(1, "20\n", 3);
	printf("un %% int %d\n", 222);
	ft_printf("un %% int %d\n\n\n", 222);
	
	return 0;
}
