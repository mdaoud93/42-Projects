
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int	get_places(unsigned int value, int base)
{
	int		count;

	count = 0;
	while (value != 0)
	{
		count++;
		value /= base;
	}
	return (count == 0 ? 1 : count);
}

char		*ft_itoa_base(int value, int base)
{
	int				negative;
	unsigned int	temp;
	int				i;
	char			*str;

	if (value < 0 && base == 10)
	{
		temp = -value;
		negative = 1;
	}
	else
	{
		temp = value;
		negative = 0;
	}
	i = get_places(temp, base);
	if ((str = malloc(i + negative + 1)) == NULL)
		return (NULL);
	str[i + negative] = '\0';
	i--;
	if (negative)
	{
		str[0] = '-';
		i++;
	}
	while (i >= negative)
	{
		str[i] = temp % base;
		str[i] += (str[i] < 10) ? '0' : 'A' - 10;
		temp /= base;
		i--;
	}
	return (str);
}

int main(int argc, char **argv)
{
	int		num;
	int		base;

	if (argc != 3)
	{
		printf("Usage: %s value base\n", argv[0]);
		return (0);
	}
	num = atoi(argv[1]);
	base = atoi(argv[2]);
	if (base <= 1 || base > 16)
	{
		printf("Invalid base, please pick a base from 2 to 16\n");
		return (0);
	}
	printf("%s\n", ft_itoa_base(num, base));
	return (0);
}