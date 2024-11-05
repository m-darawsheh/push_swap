SRCS		= check.c main.c my_atoi.c parse_arg.c strlen.c free_protection.c ft_add_back.c ft_isalpha_edit.c

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
