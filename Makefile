NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       ./strategy_disorder/disorder.c \
       ./strategy_disorder/strategy.c \
       ./strategy_disorder/Print_bench.c \
       ./operations/op1.c \
       ./operations/op2.c \
       ./operations/op3.c \
       ./operations/stack_utils2.c \
       ./operations/stack_utils.c \
       ./parsing/parsing.c \
       ./parsing/parsing_utils.c \
       ./parsing/parsing_utils2.c \
       ./parsing/ft_split.c \
       ./algo_sorts/selection_sort.c \
       ./algo_sorts/chunk_sort.c \
       ./algo_sorts/chunk_utils.c \
       ./algo_sorts/indexing.c \
       ./algo_sorts/sort_small.c \
       ./algo_sorts/sort_complex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)	

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@echo "[CC] $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

