NAME = push_swap

CC = cc

CCFLAGS = -Wall -Wextra -Werror

MY_SOURCE = ./src/main.c \
	./src/add_to_stack.c \
	./src/push_cost.c \
	./src/find_cheapest.c \
	./src/find_target.c \
	./src/free_stack.c \
	./src/init_nodes.c \
	./src/moves.c \
	./src/print_error.c \
	./src/process_args.c \
	./src/commands/ft_push.c \
	./src/commands/ft_reverse_rotate.c \
	./src/commands/ft_rotate.c \
	./src/commands/ft_swap.c \
	./src/sort_five.c \
	./src/sort_numbers.c \
	./src/sort_three.c \
	./src/sort.c \
	./src/utils/ft_split.c \
	./src/utils/utils_more.c \
	./src/utils/utils.c \

OBJ := $(MY_SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ)

.o: .c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re