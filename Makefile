SRCS		= check.c main.c my_atoi.c parse_arg.c strlen.c free_protection.c ft_add_back.c ft_isalpha_edit.c O_file.c algo.c

OBJS		= $(SRCS:%.c=obj/%.o)


CC			= cc
CFLAGS		=
NAME		= push_swap


all: libtrue $(NAME)

libtrue:
	make -C ./libtrue

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Llibtrue -ltrue

obj/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C ./libtrue clean
	rm -rf obj

fclean: clean
	make -C ./libtrue fclean
	rm -f $(NAME)

re: fclean libtrue $(NAME)

clone:
	gc -b linked_list git@github.com:AhmedHodiani/libtrue.git

.PHONY: clean fclean all re libtrue
