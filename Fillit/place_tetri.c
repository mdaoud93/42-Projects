/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:57:55 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			place_tetri(int **board, int dim, t_tetri *tetri, t_point *pos)
{
	int x;
	int y;

	while (can_place(board, dim, tetri, pos) == 0)
	{
		shift_point(dim, pos);
		if (!on_board(dim, pos))
			return (0);
	}
	x = 0;
	y = 0;
	while (x < tetri->height)
	{
		y = 0;
		while (y < tetri->width)
		{
			board[pos->x + x][pos->y + y] =
							tetri->shape[x][y] | board[pos->x + x][pos->y + y];
			y++;
		}
		x++;
	}
	free(tetri->start);
	tetri->start = pos;
	return (1);
}
