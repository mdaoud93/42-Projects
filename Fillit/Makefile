# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 17:49:53 by mdaoud            #+#    #+#              #
#    Updated: 2018/12/03 09:51:51 by mdaoud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=		fillit
CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror
HEADERS		= 		includes
SRC			=		can_place.c \
					create_board.c \
					create_point.c \
					create_tetris.c \
					fillit.c \
					free_board.c \
					free_tetri_array.c \
					ft_malloc_2d.c \
					ft_usage.c \
					input.c \
					ceil_sqrt.c \
					is_empty_col.c \
					is_empty_row.c \
					newline.c \
					on_board.c \
					place_tetri.c \
					print_board.c \
					remove_tetri.c \
					shift_point.c \
					solve_board.c \
					solve.c \
					valid_input.c \
					valid_tetris.c
				
OBJ			=		$(SRC:%.c=$(OBJ_PATH)/%.o)

OBJ_PATH	=		./objs

LIB_DIR		=		libft/
LIB			=		$(LIB_DIR)libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft -I$(HEADERS)

$(OBJ_PATH):
	mkdir -p $@

$(LIB):
	make -C $(LIB_DIR)

$(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADERS)

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re:	fclean
	$(MAKE)

.PHONY: all clean fclean re