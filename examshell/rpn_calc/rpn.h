

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define RPN_BUFFSIZE 2048

struct		s_stack
{
	int		tab[RPN_BUFFSIZE];
	int		head;
};

typedef struct s_stack t_stack;

void		push(int num, t_stack *stk);
int			pop(t_stack *stk);
void		rpn_calc(char *str, t_stack *stk);


