NAME = libftprintf.a

SRC =  ft_printf.c\
		print_i_d.c\
		print_c.c\
		print_s.c\
		print_u.c\
		utils.c\
		print_x.c\
		print_percentage.c

SRCS	=	$(addprefix srcs/, $(SRC))

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

RM = rm -f

# INCLUDES = /includes

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
