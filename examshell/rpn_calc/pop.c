
#include "rpn.h"

int			pop(t_stack *stk)
{
	stk->head--;
	return (stk->tab[stk->head]);
}