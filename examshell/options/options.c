
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static int		usage(void)
{
	write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	return (0);
}

static int		invalid_option(void)
{
	write(1, "Invalid Option\n", 15);
	return (0);
}

static int		pow_2(int power)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (power-- > 0)
		result = result << 1;
	return (result);
}

static void		print_options(int options)
{
	int		flag;
	int		space;

	write(1, "000000", 6);
	flag = pow_2(25);
	space = 6;
	while (flag > 0)
	{
		if (space == 8)
		{
			write(1, " ", 1);
			space = 0;
		}
		if (options & flag)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		space++;
		flag = flag >> 1;
	}
	write(1, "\n", 1);
}

int				main(int argc, char **argv)
{
	int		options;
	int		i;
	size_t	j;

	if (argc < 2)
		return (usage());
	i = 1;
	options = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 1;
			while (argv[i][j])
			{
				if (argv[i][j] == 'h')
					return (usage());
				else if (argv[i][j] < 'a' || argv[i][j] > 'z')
					return (invalid_option());
				options = options | pow_2(argv[i][j] - 'a');
				j++;
			}
		}
		i++;
	}
	print_options(options);
	return (0);
}