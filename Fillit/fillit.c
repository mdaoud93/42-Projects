/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:11:27 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/03 09:56:39 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetri		**tetris;
	int			count;
	int			fd;

	if (argc != 2)
	{
		ft_usage();
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstrln("error");
		return (0);
	}
	count = 0;
	if ((tetris = input(fd, &count)) == NULL)
	{
		ft_putstrln("error");
		return (0);
	}
	solve(tetris, count);
	free_tetri_array(tetris);
	free(tetris);
	tetris = NULL;
	return (0);
}
