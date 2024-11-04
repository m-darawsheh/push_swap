SRCS		= check_if_char.c check_if_duplicate.c check_if_max_min.c check_rubbish_sign.c free_protiction.c ft_add_back.c ft_create_b.c ft_isalpha_edit.c main.c my_atoi.c parse_arg.c strlen.c

OBJS		= $(SRCS:.c=.o)


CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re
