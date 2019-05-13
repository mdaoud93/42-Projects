/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:05:20 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			can_place(int **board, int dim, t_tetri *tetri, t_point *pos)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < tetri->height)
	{
		y = 0;
		while (y < tetri->width)
		{
			if (pos->x + x >= dim || pos->y + y >= dim ||
				(tetri->shape[x][y] && board[pos->x + x][pos->y + y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
