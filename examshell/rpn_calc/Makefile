TARGET		=		rpn
CC			=		clang
CFLAGS		=		-Wall -Wextra -Werror
SRC			=		main.c pop.c push.c rpn_calc.c
HEADER		=		rpn.h
OBJ			=		$(SRC:%.c=$(OBJ_PATH)/%.o)
OBJ_PATH	=		./objs

all: $(OBJ_PATH) $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
$(OBJ_PATH):
	mkdir -p $@
$(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ_PATH)
fclean: clean
	rm -f $(TARGET)
re: fclean
	$(MAKE)

.PHONY: all clean fclean re