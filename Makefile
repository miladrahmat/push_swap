NAME = push_swap
BNAME = checker
SRCS = \
	main.c check_args.c push_commands.c swap_commands.c rotate_commands.c \
	r_rotate_commands.c push_swap.c get_info.c helper_funcs.c move_to_a.c \
	move_to_b.c
BRCS = \
	checker_bonus.c check_args.c swap_commands.c push_commands.c \
	rotate_commands.c r_rotate_commands.c helper_funcs.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BOBJS) $(LIBFT) -o $(BNAME)

$(LIBFT):
	@make -C libft

clean:
	@rm -fr $(OBJS) $(BOBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@make fclean -C libft
		
re: fclean all

.PHONY: all clean fclean re