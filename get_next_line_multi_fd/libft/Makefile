

NAME			=	libft.a
CC				= 	gcc
CFlAGS			=	-Wall -Werror -Wextra
HEADERS			=	includes
OBJ				=	$(SRC:.c=.o)
SRC		 		= 	ft_atoi.c \
					ft_bzero.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_itoa.c \
					ft_lstadd_tail.c \
					ft_lstadd_head.c \
					ft_lstadd_tail.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstprint_node.c \
					ft_lstremove.c \
					ft_lstsplit.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putchar.c \
					ft_putendl_fd.c \
					ft_putendl.c \
					ft_putnbr_fd.c \
					ft_putnbr.c \
					ft_putnbrln.c \
					ft_putstr_fd.c \
					ft_putstr.c \
					ft_putstrln_fd.c \
					ft_putstrln.c \
					ft_strcat.c \
					ft_strchr.c \
					ft_strclr.c \
					ft_strcmp.c \
					ft_strcontains.c \
					ft_strcpy.c \
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strrev.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtok.c \
					ft_strtrim.c \
					ft_tolower.c \
					ft_toupper.c

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

$(OBJ_PATH):
	mkdir -p $@

%.o: %.c
	$(CC) $(CFlAGS) -o $@ -c $< -I$(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re