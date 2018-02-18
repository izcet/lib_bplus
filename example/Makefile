# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/23 23:07:18 by irhett            #+#    #+#              #
#    Updated: 2017/05/05 20:50:06 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test	

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -g

SRC_DIR		=	src
SRC_FILE	=	main.c print_data.c
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

LIBFT_DIR	=	../libft
LIBFT_INC	=	$(LIBFT_DIR)/inc
LIBFT		=	$(LIBFT_DIR)/libft.a

LIBTREE_DIR	=	..
LIBTREE_INC	=	$(LIBTREE_DIR)/inc
LIBTREE		=	$(LIBTREE_DIR)/libbplus.a

INC_DIR		=	-I inc -I $(LIBFT_INC) -I $(LIBTREE_INC)

.PHONY: all clean fclean re

all: $(LIBFT) $(LIBTREE) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INC_DIR) -o $(NAME) $(LIBTREE) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $^ $(FLAGS) $(INC_DIR) -o $@

clean:
	@cd $(LIBFT_DIR) && make clean
	@cd $(LIBTREE_DIR) && make clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@cd $(LIBTREE_DIR) && make fclean
	@cd $(LIBFT_DIR) && make fclean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBTREE):
	@$(MAKE) -C $(LIBTREE_DIR)
