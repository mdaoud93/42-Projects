make -C libft
gcc -Wall -Werror -Wextra get_next_line.c main.c -L libft/ -lft -I libft/includes
# cd libft/
# make fclean