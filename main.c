#include "ft_printf.h"

int main()
{
	char	a;
	a = 66;

	printf("printf :\n%5c\n", 'b');
	ft_printf("ft_printf|ft_printf :\n%5c\n", 'b');
	printf("printf :\n%c\n", 'b');
	ft_printf("ft_printf|ft_printf :\n%c\n", 'b');
	printf("printf :\n%-5c\n", 'b');
	ft_printf("ft_printf|ft_printf :\n%-5c\n", 'b');

	

	write(1, "1\n", 2);
	
	printf("   printf|un %% int %-*.5d\n", 3, -1);
	ft_printf("ft_printf|un %% int %-*.5d\n\n\n", 3, -1);
 
 	write(1, "2\n", 2);
	printf("   printf|un %% int %0*.5d\n", 3, -1);
	ft_printf("ft_printf|un %% int %0*.5d\n\n\n", 3, -1);

	write(1, "3\n", 2);
	printf("   printf|un %% int %-*.3d\n", 5, -1);
	ft_printf("ft_printf|un %% int %-*.3d\n\n\n", 5, -1);

	write(1, "4\n", 2);
	printf("   printf|un %% int %0*.3d\n", 5, -1);
	ft_printf("ft_printf|un %% int %0*.3d\n\n\n", 5, -1);

	write(1, "5\n", 2);
	printf("   printf|un %% int %.5d\n", -1);
	ft_printf("ft_printf|un %% int %.5d\n\n\n", -1);
	
	write(1, "6\n", 2);
	printf("   printf|un %% int %5d\n", -1);
	ft_printf("ft_printf|un %% int %5d\n\n\n", -1);

	write(1, "7\n", 2);
	printf("   printf|un %% int %5.d\n", -1);
	ft_printf("ft_printf|un %% int %5.d\n\n\n", -1);

	write(1, "8\n", 2);
	printf("   printf|un %% int %-5d\n", -1);
	ft_printf("ft_printf|un %% int %-5d\n\n\n", -1);

	write(1, "9\n", 2);
	printf("   printf|un %% int %05d\n", -1);
	ft_printf("ft_printf|un %% int %05d\n\n\n", -1);

	write(1, "10\n", 3);
	printf("   printf|un %% int %d\n", -1);
	ft_printf("ft_printf|un %% int %d\n\n\n", -1);

	write(1, "11\n", 3);
	printf("   printf|un %% int %-*.5d\n", 3, 22);
	ft_printf("ft_printf|un %% int %-*.5d\n\n\n", 3, 22);
	
	write(1, "12\n", 3);
	printf("   printf|un %% int %0*.5d\n", 3, 22);
	ft_printf("ft_printf|un %% int %0*.5d\n\n\n", 3, 22);
	
	write(1, "13\n", 3);
	printf("   printf|un %% int %-*.3d\n", 5, 22);
	ft_printf("ft_printf|un %% int %-*.3d\n\n\n", 5, 22);
	
	write(1, "14\n", 3);
	printf("   printf|un %% int %0*.3d\n", 5, 22);
	ft_printf("ft_printf|un %% int %0*.3d\n\n\n", 5, 22);
	
	write(1, "15\n", 3);
	printf("   printf|un %% int %.5d\n", 22);
	ft_printf("ft_printf|un %% int %.5d\n\n\n", 22);
	
	write(1, "16\n", 3);
	printf("   printf|un %% int %5d\n", 22);
	ft_printf("ft_printf|un %% int %5d\n\n\n", 22);

	write(1, "17\n", 3);
	printf("   printf|un %% int %5.d\n", 22);
	ft_printf("ft_printf|un %% int %5.d\n\n\n", 22);

	write(1, "18\n", 3);
	printf("   printf|un %% int %-5d\n", 22);
	ft_printf("ft_printf|un %% int %-5d\n\n\n", 22);

	write(1, "19\n", 3);
	printf("   printf|un %% int %05d\n", 22);
	ft_printf("ft_printf|un %% int %05d\n\n\n", 22);

	write(1, "20\n", 3);
	printf("   printf|un %% int %d\n", 222);
	ft_printf("ft_printf|un %% int %d\n\n\n", 222);

		write(1, "21\n", 3);
	printf("   printf|un %% int %-*.5d\n", 0, 0);
	ft_printf("ft_printf|un %% int %-*.5d\n\n\n", 0, 0);
	
	write(1, "22\n", 3);
	printf("   printf|un %% int %0*.5d\n", 0, 0);
	ft_printf("ft_printf|un %% int %0*.5d\n\n\n", 3, 0);
	
	write(1, "23\n", 3);
	printf("   printf|un %% int %-*.3d\n", 0, 0);
	ft_printf("ft_printf|un %% int %-*.3d\n\n\n", 0, 0);
	
	write(1, "24\n", 3);
	printf("   printf|un %% int %0*.3d\n", 0, 0);
	ft_printf("ft_printf|un %% int %0*.3d\n\n\n", 0, 0);
	
	write(1, "25\n", 3);
	printf("   printf|un %% int %.5d\n", 0);
	ft_printf("ft_printf|un %% int %.5d\n\n\n", 0);
	
	write(1, "26\n", 3);
	printf("   printf|un %% int %5d\n", 0);
	ft_printf("ft_printf|un %% int %5d\n\n\n", 0);

	write(1, "27\n", 3);
	printf("   printf|un %% int %5.d\n", 0);
	ft_printf("ft_printf|un %% int %5.d\n\n\n", 0);

	write(1, "28\n", 3);
	printf("   printf|un %% int %-5d\n", 0);
	ft_printf("ft_printf|un %% int %-5d\n\n\n", 0);

	write(1, "29\n", 3);
	printf("   printf|un %% int %05d\n", 0);
	ft_printf("ft_printf|un %% int %05d\n\n\n", 0);

	write(1, "30\n", 3);
	printf("   printf|un %% int %d\n", 0);
	ft_printf("ft_printf|un %% int %d\n\n\n", 0);
	
	return 0;
}
