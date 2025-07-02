NAME = push_swap

SRC = main.c stack.c utils.c operations1.c operations2.c operations3.c \
	parser.c sort_two.c sort_three.c sort_four.c \
		sort_five.c index_stack.c radix_sort.c butterfly_sort.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -I$(LIBFT_DIR) -I. -g3

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

