#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <stdarg.h>

typedef struct s_flag
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	precision;
} t_flag;

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_putnbr_fd(int n, int fd);
int					ft_printf(const char *str, ...);
int					numlen(int number);
void				ft_putchar_fd(char c, int fd);


#endif