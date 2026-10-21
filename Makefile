NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

LIBFT = libft/libft.a

SRCS = main.c disorder.c op1.c op2.c parsing.c parsing_utils.c push.c revers_rot_and_op.c stack_utils.c sort_small.c selection_sort.c chunk_sort.c chunk_utils.c indexing.c strategy.c Print_bench.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)	

$(LIBFT) :
	@make --no-print-directory -C libft

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c
	@echo "[CC] $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make --no-print-directory -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C libft fclean

re: fclean all

