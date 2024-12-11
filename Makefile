SRCS		= main.c check.c parse_arg.c my_atoi.c ft_isalpha_edit.c strlen.c algo.c

OBJS		= $(SRCS:%.c=obj/%.o)


CC			= cc
CFLAGS		=
NAME		= push_swap


all: libft libtrue $(NAME)

libtrue:
	make -C ./libtrue

libft:
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Llibtrue -ltrue -Llibft -lft

obj/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C ./libft clean
	make -C ./libtrue clean
	rm -rf obj

fclean: clean
	make -C ./libft fclean
	make -C ./libtrue fclean
	rm -f $(NAME)

re: fclean libft libtrue $(NAME)

clone:
	gc -b linked_list git@github.com:AhmedHodiani/libtrue.git

.PHONY: clean fclean all re libtrue libft
