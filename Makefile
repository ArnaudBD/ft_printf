NAME = libprintf.a

SRCS =  ft_printf.c\
		print_i_d.c\
		stdarg_tests.c\ 
		parsing.c\
		print_s.c\
		test_struct.c\ 
		print_X_.c\
		print_u.c\
		utils.c\
		basic_tests.c\
		main.c\
		print_c.c\
		print_x.c\
		xtests.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ft_printf.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re	