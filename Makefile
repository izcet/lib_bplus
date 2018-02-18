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

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -c -g

LIB			=	ar rc
RLIB		=	ranlib

SRC_DIR		=	src
SRC_FILE	=	add_leaf.c \
				can_pull_from_left.c \
				can_pull_from_right.c \
				can_share.c \
				condense.c \
				del_leaf.c \
				del_node.c \
				del_ptr_at.c \
				error.c \
				for_each_tree_node.c \
				get_first_of_key.c \
				get_index.c \
				get_index_of_child.c \
				get_leaf.c \
				get_left.c \
				get_leftmost_child.c \
				get_lowest_key.c \
				get_right.c \
				get_rightmost_child.c \
				ins_ptr_at.c \
				ins_ptr_in_node.c \
				is_full.c \
				make_space.c \
				merge_left.c \
				merge_right.c \
				new_empty_tree.c \
				new_leaf.c \
				new_node.c \
				pass_ptr_left.c \
				pass_ptr_right.c \
				remove.c \
				remove_leaf.c \
				rm_leaf.c \
				shift_ptrs_left.c \
				shift_ptrs_right.c \
				split_right.c \
				split_root.c \
				update_keys.c \
				update_leaf.c 
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC_DIR		=	-I inc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(LIB) $@ $(OBJS)
	$(RLIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $^ $(FLAGS) $(INC_DIR) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
