NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRCS = disorder.c op1.c op2.c parsing.c parsing_utils.c push.c revers_rot_and_op.c stack_utils.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)	

$(LIBFT) :
	@make -C libft

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $@

%.o: %.c
	@echo "[CC] $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

