NAME = get_next_line

SRCS = get_next_line.c

INCLS = ./includes/

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	 clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
fclean:
	    rm test_gnl get_next_line.o main.o

re: fclean all
