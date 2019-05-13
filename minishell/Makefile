# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 21:06:11 by mdaoud            #+#    #+#              #
#    Updated: 2019/03/06 14:21:08 by mdaoud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell
CC				= 	clang
CFlAGS			=	-Wall -Werror -Wextra -Ofast
HEADERS			=	-I includes -I libft/includes
LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a

SRC				=	add_env_var.c \
					builtin_cd.c \
					builtin_echo.c \
					builtin_env.c \
					builtin_setenv.c \
					builtin_unsetenv.c \
					change_directory.c \
					check_cmd_format.c \
					dispatch_env_cmd.c \
					display_prompt.c \
					free_shell.c \
					free_string_array.c \
					get_count.c \
					get_env_value.c \
					get_var_ind.c \
					handler_sigint.c \
					main.c \
					process_cmd.c \
					process_input.c

OBJ_PATH			=	./objs

OBJ				=	$(SRC:%.c=$(OBJ_PATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ_PATH) $(LIB) $(OBJ)
	$(CC) $(CFlAGS) $(HEADERS) $(OBJ) -o $@ -L $(LIB_PATH) -lft

$(OBJ_PATH):
	mkdir -p $@

$(OBJ_PATH)/%.o: %.c
	$(CC) $(CFlAGS) -o $@ -c $< $(HEADERS)

$(LIB):
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re