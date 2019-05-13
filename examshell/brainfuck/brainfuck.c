

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BF_BUFF_SIZE 2048

static void			interpret(char *arg, char *str)
{
	int		i;
	int		bracket;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '>')
			str++;
		else if (arg[i] == '<')
			str--;
		else if (arg[i] == '+')
			(*str)++;
		else if (arg[i] == '-')
			(*str)--;
		else if (arg[i] == '[' && !*str)
		{
			bracket = 1;
			i++;
			while (bracket != 0)
			{
				if (arg[i] == '[')
					bracket++;
				else if (arg[i] == ']')
					bracket--;
				i++;

			}
		}
		else if (arg[i] == ']' && *str)
		{
			bracket = 1;
			i--;
			while (bracket != 0)
			{
				if (arg[i] == '[')
					bracket--;
				else if (arg[i] == ']')
					bracket++;
				i--;
			}
		}
		else if (arg[i] == '.')
			write(1, str, 1);
		i++;
	}
}

static int		invalid_format(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == '[')
			count++;
		else if (*str == ']')
			count--;
		str++;
	}
	return (count != 0);
}

int		main(int argc, char **argv)
{	
	int		i;
	char	str[BF_BUFF_SIZE];

	if (argc < 2)
	{
		printf("Usage: %s string1 [string2] [string3]...\n", argv[0]);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		memset(str, 0, BF_BUFF_SIZE);
		if (invalid_format(argv[i]))
		{
			printf("Invalid format.\n");
			return (0);
		}
		interpret(argv[i], str);
		printf("\n");
		i++;
	}
}