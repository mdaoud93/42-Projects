
#include "rpn.h"

static int		is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int		is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

static int		check_op(char op, t_stack *stk)
{
	int		num1;
	int		num2;

	if (stk->head <= 1)
	{
		printf("Error\n");
		return (0);
	}
	num1 = stk->tab[stk->head - 2];
	num2 = stk->tab[stk->head - 1];
	if ((op == '/' && num2 == 0) || (op == '%' && num2 == 0))
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}

static void		do_op(char op, t_stack *stk)
{
	int		num1;
	int		num2;

	num2 = pop(stk);
	num1 = pop(stk);
	if (op == '+')
		push(num1 + num2, stk);
	else if (op == '-')
		push(num1 - num2, stk);
	else if (op == '*')
		push(num1 * num2, stk);
	else if (op == '/')
		push(num1 / num2, stk);
	else if (op == '%')
		push(num1 % num2, stk);
}

void		rpn_calc(char *str, t_stack *stk)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && is_num(str[i + 1]))
		{
			push(atoi(str + i), stk);
			i++;
			while (str[i] && is_num(str[i]))
				i++;
		}
		if (is_num(str[i]))
		{
			push(atoi(str + i), stk);
			while (str[i] && is_num(str[i]))
				i++;
		}
		else if (is_op(str[i]))
		{
			if (!check_op(str[i], stk))
				return ;
			do_op(str[i], stk);
		}
		else if (str[i] != ' ')
		{
			printf("Error\n");
			return ;
		}
		i++;
	}
	if (stk->head != 1)
	{
		printf("Error\n");
		return ;
	}
	printf("%d\n", stk->tab[stk->head - 1]);
}
