NAME = libftprintf.a

SRC =  ft_printf.c\
		print_i_d.c\
		print_c.c\
		print_s.c\
		print_u.c\
		utils.c\
		utils2.c\
		utils3.c\
		print_x.c\
		print_percentage.c\
		print_p.c\

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
	$(AR) $(NAME) $(OBJS)
#	make -C libft
#	cp libft/libft.a $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
# 	make clean -C libft

fclean: clean
	$(RM) $(NAME)
# 	make fclean -C libft

re: fclean all

.PHONY:
	all clean fclean re
