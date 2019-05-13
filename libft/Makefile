

NAME			=	libft.a
CC				= 	gcc
CFlAGS			=	-Wall -Werror -Wextra
HEADERS			=	includes

SRC				=	./src

GNL_DIR			=	GNL
GNL_FILES		=	get_next_line.c

IO_DIR		 	= 	IO
IO_FILES		=	ft_putchar_fd.c \
					ft_putchar.c \
					ft_putendl.c \
					ft_putnbr_fd.c \
					ft_putnbr.c \
					ft_putnbrln.c \
					ft_putstr_fd.c \
					ft_putstr.c \
					ft_putstrln.c \
					ft_putstrln.c

LIST_DIR		=	List
LIST_FILES		=	ft_lstappend.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstprint_node.c \
					ft_lstpush.c \
					ft_lstremove.c \
					ft_lstsplit.c

MEMORY_DIR		=	Memory
MEMORY_FILES	=	ft_bzero.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c

STRING_DIR		=	String
STRING_FILES	=	ft_atoi.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_itoa.c \
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
					ft_strreplace.c \
					ft_strrev.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtok.c \
					ft_strtrim.c \
					ft_tolower.c \
					ft_toupper.c \

OBJ_DIR			=	./objs

OBJ				=	$(IO_FILES:%.c=$(OBJ_DIR)/$(IO_DIR)/%.o) \
					$(LIST_FILES:%.c=$(OBJ_DIR)/$(LIST_DIR)/%.o) \
					$(MEMORY_FILES:%.c=$(OBJ_DIR)/$(MEMORY_DIR)/%.o) \
					$(STRING_FILES:%.c=$(OBJ_DIR)/$(STRING_DIR)/%.o) \
					$(GNL_FILES:%.c=$(OBJ_DIR)/$(GNL_DIR)/%.o)

ALL_DIR			=	$(OBJ_DIR) \
					$(OBJ_DIR)/$(IO_DIR) \
					$(OBJ_DIR)/$(LIST_DIR) \
					$(OBJ_DIR)/$(MEMORY_DIR) \
					$(OBJ_DIR)/$(STRING_DIR) \
					$(OBJ_DIR)/$(GNL_DIR)

all: $(NAME)

$(NAME): $(ALL_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

$(ALL_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC)/%.c
	$(CC) $(CFlAGS) -o $@ -c $< -I$(HEADERS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re