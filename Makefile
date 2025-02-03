NAME			= $(BUILD_PATH)/push_swap
NAME_CHECKER	= checker
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
BUILD_PATH		?= ./build

DEPENDENCIES		= libft libtrue libftprintf libgnl
DEPENDENCIES_DIR	= ./dependencies
DEPENDENCIES_FLAGS	= $(foreach lib,$(DEPENDENCIES),-L$(BUILD_PATH)/$(lib)) \
						$(foreach lib,$(patsubst lib%,%, $(DEPENDENCIES)),-l$(lib))
INCLUDE_FLAGS		= -Iinclude $(foreach lib,$(DEPENDENCIES),-Iinclude/$(lib))

SRCS			= src/strlen.c src/parse_arg.c \
					src/my_atoi.c src/main.c \
					src/ft_isalpha_edit.c src/check.c \
					src/algorithm.c src/utils.c \
					src/algorithm_utils.c src/turquoise_utils.c
OBJS			= $(SRCS:src/%.c=$(BUILD_PATH)/obj/%.o)

CHECKER_SRCS	= src/checker/main.c src/algorithm.c src/parse_arg.c \
					src/my_atoi.c src/strlen.c src/check.c \
					src/ft_isalpha_edit.c src/utils.c \
					src/algorithm_utils.c src/turquoise_utils.c
CHECKER_OBJS	= $(CHECKER_SRCS:src/%.c=$(BUILD_PATH)/obj/%.o)

HEADER_FILES	= include/push_swap.h

all: $(NAME) $(NAME_CHECKER)

$(NAME): $(OBJS) $(foreach lib,$(DEPENDENCIES),$(BUILD_PATH)/$(lib)/$(lib).a) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJS) $(DEPENDENCIES_FLAGS) $(INCLUDE_FLAGS) -o $(NAME)

$(NAME_CHECKER): $(BUILD_PATH)/$(NAME_CHECKER) $(HEADER_FILES)

$(BUILD_PATH)/$(NAME_CHECKER): $(CHECKER_OBJS) $(foreach lib,$(DEPENDENCIES),$(BUILD_PATH)/$(lib)/$(lib).a)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(DEPENDENCIES_FLAGS) $(INCLUDE_FLAGS) -o $(BUILD_PATH)/$(NAME_CHECKER)

$(foreach lib,$(DEPENDENCIES),$(BUILD_PATH)/$(lib)/$(lib).a):
	$(MAKE) -C $(DEPENDENCIES_DIR)/$(basename $(@F)) BUILD_PATH=../../$(BUILD_PATH)/$(basename $(@F)) all

$(BUILD_PATH)/obj/%.o: src/%.c $(HEADER_FILES)
	@mkdir -p $(BUILD_PATH)/obj/checker
	$(CC) $(CFLAGS) $(DEPENDENCIES_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_PATH)/obj
	@rm -rf $(BUILD_PATH)/lib*/obj

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BUILD_PATH)

re: fclean all

.PHONY: all clean re fclean
