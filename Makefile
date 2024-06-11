NAME = push_swap
SRCS = \
	main.c check_args.c push_commands.c swap_commands.c rotate_commands.c \
	r_rotate_commands.c push_swap.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(OBJS) $(LIBFT) $(NAME)

$(LIBFT):
		@make -C libft

clean:
		rm -fr $(OBJS)
		@make clean -C libft

fclean: clean
		rm -f $(NAME)
		@make fclean -C libft
		
re: fclean all

.PHONY: all clean fclean re