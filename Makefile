NAME = 

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)	


$(NAME) : $(OBJS)
	    @ar rcs $(NAME) $(OBJS)

%.o: %.c
	@echo "[CC] $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

