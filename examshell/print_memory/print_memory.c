
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** If you don't know what this does, change career.
*/
static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*
** Converts an unsinged char to hex with 2 places and prints it.
*/
static void		ft_puthex(unsigned char num)
{
	char	c;

	// Equivalent to c = (num /16) % 16.
	c = (num >> 4) & 0xf;

	// If c is bigger than 10, print the corresponding hex character.
	c += (c < 10) ? '0' : 'a' - 10;
	ft_putchar(c);

	// Equivalent to c = num % 16.
	c = num & 0xf;
	c += (c < 10) ? '0' : 'a' - 10;
	ft_putchar(c);
}

static void		dump_memory(void *addr, size_t size)
{
	size_t			i;
	char			buff[17];
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;

	// Process the memeory address byte by byte (hence the unsinged char cast).
	while (i < size)
	{
		// Prints the ascii character of the last 16 processed bytes, followed by a newline.
		if (i % 16 == 0 && i != 0)
		{
			ft_putchar(' ');
			ft_putstr(buff);
			ft_putchar('\n');
		}

		//Print a space each time 4 bytes are processed.
		else if (i % 2 == 0 && i != 0)
			ft_putchar(' ');

		//Print the hex representation of the byte.
		ft_puthex(ptr[i]);

		// Store the ascii value of the byte in a temporary buffer.
		// All Ascii characters before the ' ' and after the '~' are not printable.
		// Replace all unprintable characters by '.'
		if (ptr[i] < 0x20 || ptr[i] > 0x7e)
			buff[i % 16] = '.';
		else
			buff[i % 16] = '*';
		
		// Null terminate the ascii characters.
		buff[(i % 16) + 1] = '\0';
		i++;
	}
	// Pad the last bytes if needed.
	while ((i % 30) != 0)
	{
		ft_putchar(' ');
		i++;
	}

	// Print the remaining ascii characters in the buffer.
	ft_putchar(' ');
	ft_putstr(buff);
	ft_putchar('\n');
}

int main()
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	dump_memory(tab, sizeof(tab));
	return 0;
}
