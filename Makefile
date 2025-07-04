# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsahakya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 10:49:53 by nsahakya          #+#    #+#              #
#    Updated: 2025/07/04 15:36:51 by nsahakya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./include -I./libft

AR          = ar rcs
RM          = rm -f

SRC_DIR     = src
BONUS_DIR   = src_bonus
OBJ_DIR     = obj
OBJ_BONUS   = obj_bonus
LIBFT_DIR   = ../libft
LIBFT       = $(LIBFT_DIR)/libft.a

# ------------------------------------------------------------------------------

SRCS = main.c stack.c utils1.c utils2.c parser.c operations1.c operations2.c \
       sort_two.c sort_three.c sort_four.c sort_five.c index_stack.c \
       butterfly_sort.c operations3.c

BONUS_SRCS = checker.c get_next_line.c get_next_line_utils.c \
             stack_bonus.c operations1_bonus.c operations2_bonus.c \
			 operations3_bonus.c parser_bonus.c utils1_bonus.c utils2_bonus.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJ_BONUS)/, $(BONUS_SRCS:.c=.o))

# ------------------------------------------------------------------------------

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS):
	mkdir -p $(OBJ_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS)/%.o: $(BONUS_DIR)/%.c | $(OBJ_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	$(RM) -r $(OBJ_DIR) $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

