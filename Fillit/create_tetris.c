/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:16:09 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/08 16:05:29 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	gen_shape(t_tetri *t, int array[DIM][DIM])
{
	int		x;
	int		y;
	t_point	*s;

	s = t->start;
	if ((t->shape = ft_malloc_2d(t->height, t->width)) == NULL)
		return ;
	x = 0;
	while (x < t->height)
	{
		y = 0;
		while (y < t->width)
		{
			t->shape[x][y] = array[x + s->x][y + s->y];
			y++;
		}
		x++;
	}
}

static void	calc_dim(t_tetri *t, int array[DIM][DIM])
{
	t_point		*c;
	t_point		*l;

	if ((c = create_point(0, DIM - 1)) == NULL)
		return ;
	if ((l = create_point(0, DIM - 1)) == NULL)
	{
		free(c);
		return ;
	}
	while (c->x < DIM && is_empty_col(c->x, array))
		c->x++;
	while (c->y >= 0 && is_empty_col(c->y, array))
		c->y--;
	while (l->x < DIM && is_empty_row(l->x, array))
		l->x++;
	while (l->y >= 0 && is_empty_row(l->y, array))
		l->y--;
	t->width = c->y - c->x + 1;
	t->height = l->y - l->x + 1;
	t->start->x = l->x;
	t->start->y = c->x;
	free(c);
	free(l);
}

static void	to_binary(char *str, int array[4][4])
{
	int			x;
	int			y;
	int			it;

	it = 0;
	while (str[it])
	{
		x = 0;
		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				if (str[it] == '.')
					array[x][y] = 0;
				else
					array[x][y] = 1;
				y++;
				it++;
			}
			it++;
			x++;
		}
	}
}

t_tetri		*create_tetris(char *str)
{
	int			array[4][4];
	t_tetri		*t;

	to_binary(str, array);
	if (!valid_tetris(array))
		return (NULL);
	if ((t = malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	t->start = malloc(sizeof(t_point));
	if (t->start == NULL)
		return (NULL);
	calc_dim(t, array);
	gen_shape(t, array);
	return (t);
}
