# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 13:52:36 by jdugoudr          #+#    #+#              #
#    Updated: 2019/04/02 16:29:55 by mdaoud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
CFLAGS		=	-Wall -Wextra
RM			=	rm -rf
NAME		=	ft_select
HEAD_DIR	=	includes
LIB_DIR		=	libft/
LIB_FT		=	libft/libft.a
LIB_HEAD	=	$(addprefix $(LIB_DIR), $(HEAD_DIR))
OBJ_DIR		=	objs/
VPATH		=	srcs \
				srcs/keypresses
VPATH 		+=	includes
SRCS 		=	detect_key_presses.c \
				display_list.c \
				display_selected.c \
				free_select.c \
				ft_exit.c \
				get_cursor_pos.c \
				init_signal_handlers.c \
				init_term.c \
				lst_append.c \
				main.c \
				process_keypress.c \
				restore_default_conf.c \
				tputs_char.c \
				keypress_del.c \
				keypress_down.c \
				keypress_end.c \
				keypress_home.c \
				keypress_left.c \
				keypress_right.c \
				keypress_space.c \
				keypress_up.c

HEADERS		=	ft_select.h \
				libft.h

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): libft $(OBJ_DIR) $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LIB_FT) -I $(HEAD_DIR) -I $(LIB_HEAD) -ltermcap

libft:
	@make -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD_DIR) -I $(LIB_HEAD)
$(OBJ_DIR):
	mkdir $@
clean:
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJ_DIR)
fclean: clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME)
re: fclean all
.PHONY: all libft clean fclean re