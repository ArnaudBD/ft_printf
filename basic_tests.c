#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	char	*str = "salut !";
	int		*ptr;
	int		num;
	char	type;

	type = 'i';
	num = -123;
	ptr = &num;

	printf("%.5i\n", *ptr);
	printf("%8s\n", str);

	return (0);
}