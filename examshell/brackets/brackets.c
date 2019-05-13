#include <stdio.h>
#include <unistd.h>
#include <unistd.h>


static void		check(char *str)
{
	char	mat[2048];
	int		head;
	int		i;

	head = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			mat[head++] = str[i];
		else if (str[i] == ']')
		{
			if (head == 0 || mat[head - 1] != '[')
			{
				write(1, "Error\n", 6);
				return ;
			}
			head--;
		}
		else if (str[i] == '}')
		{
			if (head == 0 || mat[head - 1] != '{')
			{
				write(1, "Error\n", 6);
				return ;
			}
			head--;
		}
		else if (str[i] == ')')
		{
			if (head == 0 || mat[head - 1] != '(')
			{
				write(1, "Error\n", 6);
				return ;
			}
			head--;
		}
		i++;
	}
	if (head == 0)
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
}

int				main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		check(argv[i]);
		i++;
	}

}