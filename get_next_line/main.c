/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:02:59 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/23 17:02:19 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{



	(void)argv;
	(void)argc;
	int fd;

	fd = open("libft.h", O_RDWR | O_CREAT , 777);
	char	*line;
	int		retval;


	line = NULL;
	// ft_putnbrln(fd);
	while ((retval = get_next_line(fd, &line)) > 0)
	{
		// ft_putnbrln(retval);
		//ft_putstr("					line is: \"");
		ft_putstr(line);
		//ft_putchar('"');
		ft_putendl();
		ft_strdel(&line);
	 	//ft_putnbrln(retval);

	}
	 	// ft_putnbrln(retval);


/*
	char buff[500];

	while ((retval = read(18, buff, 32)))
	{
			ft_putstrln(buff);
		// ft_strdel(&line);
	}
	close(17);
	return (0);
	*/
}
