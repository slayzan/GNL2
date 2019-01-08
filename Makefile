NAME = get_next_line

SRCS = get_next_line.c

INCLS = ./includes/

all: $(NAME)

$(NAME):
	    gcc $(SRCS) -o test -I $(INCLS) libft/libft.a

fclean:
	    rm test

re: fclean all
