# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/23 23:07:18 by irhett            #+#    #+#              #
#    Updated: 2017/05/05 20:56:11 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libbplus.a

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -c -g

LIB			=	ar rc
RLIB		=	ranlib

SRC_DIR		=	src
SRC_FILE	=	add_leaf.c \
				can_pull.c \
				can_share.c \
				condense.c \
				del_ptr_at.c \
				for_each_tree_node.c \
				get_edge_child.c \
				get_first_of_key.c \
				get_index.c \
				get_leaf.c \
				get_lowest_key.c \
				get_neighbor.c \
				ins_ptr_at.c \
				ins_ptr_in_node.c \
				is_full.c \
				make_space.c \
				merge.c \
				new_empty_tree.c \
				pass_ptr.c \
				remove.c \
				remove_leaf.c \
				rm_leaf.c \
				shift_ptrs_left.c \
				shift_ptrs_right.c \
				split.c \
				t_leaf.c \
				t_node.c \
				update.c
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

LIBFT_DIR	=	libft
LIBFT_INC	=	$(LIBFT_DIR)/inc
LIBFT		=	$(LIBFT_DIR)/libft.a

INC_DIR		=	-I inc -I $(LIBFT_INC)

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(LIB) $@ $(OBJS)
	$(RLIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $^ $(FLAGS) $(INC_DIR) -o $@

clean:
	@cd $(LIBFT_DIR) && make clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@cd $(LIBFT_DIR) && make fclean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
