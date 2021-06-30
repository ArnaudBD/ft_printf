#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>


typedef struct s_flag
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	precision;
	int ret;
} t_flag;

void				ft_putstr_ret(char *s, t_flag *flag);
int					ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_putnbr_ret(long long int n, t_flag *flag);
int					ft_printf(const char *str, ...);
int					numlen(long long int number);
void				ft_putchar_ret(char c, t_flag *flag);
void				print_i_d(int number, t_flag *flag);
void				print_u(unsigned int number, t_flag *flag);
void				print_s(const char *string, t_flag *flag);
void				print_c(const void *c, t_flag *flag);
void				print_x(unsigned int nbr, t_flag *flag, char *base);
void				print_X(int nbr, t_flag *flag);
void				print_xchar(int x, char c, t_flag *flag);
void				print_p(uintptr_t number, t_flag *flag, char *base);
void				print_percentage(t_flag *flag);
int					reslen(unsigned int number, char *base, int dot);
char				*convert_base(unsigned int number, char *base, t_flag *flag);







#endif