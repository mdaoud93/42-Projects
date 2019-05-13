

#include "rpn.h"

void		push(int num, t_stack *stk)
{
	stk->tab[stk->head++] = num;
}
