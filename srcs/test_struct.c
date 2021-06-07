#include <unistd.h>
#include <stdio.h>


typedef struct s_list
{
	int var;
} t_list;

int	main()
{
	t_list *flag;

	flag->var = 2;

	printf("%d\n", flag->var);
	return 0;
}