/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:43:38 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/08 16:05:53 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	create_map(char map[MAX_TETRIMINIO])
{
	int		i;

	i = 0;
	while (i < 26)
	{
		map[i] = i + 'A';
		i++;
	}
}

static char	**output_board(int dim)
{
	int		i;
	int		j;
	char	**output;

	i = 0;
	if ((output = malloc(dim * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	while (i < dim)
	{
		j = 0;
		if ((output[i] = malloc(dim * sizeof(char))) == NULL)
			return (NULL);
		while (j < dim)
		{
			output[i][j] = '.';
			j++;
		}
		i++;
	}
	return (output);
}

static void	convert(t_tetri **t, char map[], char **res)
{
	int		x;
	int		y;
	int		ind;

	ind = 0;
	while (t[ind])
	{
		x = 0;
		while (x < t[ind]->height)
		{
			y = 0;
			while (y < t[ind]->width)
			{
				if (t[ind]->shape[x][y])
					res[x + t[ind]->start->x][y + t[ind]->start->y] = map[ind];
				y++;
			}
			x++;
		}
		ind++;
	}
}

void		print_board(int dim, t_tetri **tetris)
{
	char	map[MAX_TETRIMINIO];
	char	**output;
	int		w;
	int		h;

	create_map(map);
	if ((output = output_board(dim)) == NULL)
	{
		free_board(&output, dim);
		return ;
	}
	convert(tetris, map, output);
	h = 0;
	while (h < dim)
	{
		w = 0;
		while (w < dim)
		{
			ft_putchar(output[h][w]);
			w++;
		}
		ft_putendl();
		h++;
	}
	free_board(&output, dim);
}
