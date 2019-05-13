

#include "rpn.h"

int				main(int argc, char **argv)
{
	t_stack	stack;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	stack.head = 0;
	rpn_calc(argv[1], &stack);
	return (0);
}