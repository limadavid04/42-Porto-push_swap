# # -*- Makefile -*-
CC = cc
CFLAGS =-Wall -Wextra -Werror -g #-fsanitize=address
LIBFT = ./libft/libft.a
NAME = push_swap
FILES = main utils moves moves2 moves3 push_swap\
push_swap_100 utils2 push_big_nbrs_utils

all: $(NAME)

$(NAME): $(FILES:=.o)
	$(MAKE)  -C ./libft
	$(CC) $(CFLAGS) $(FILES:=.o) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(FILES:=.o)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)
