/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:57:44 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			remove_tetri(int **board, t_tetri *tetri)
{
	int		x;
	int		y;
	t_point *pos;

	x = 0;
	y = 0;
	pos = tetri->start;
	while (x < tetri->height)
	{
		y = 0;
		while (y < tetri->width)
		{
			if (tetri->shape[x][y])
				board[x + pos->x][y + pos->y] = 0;
			y++;
		}
		x++;
	}
	tetri->start = NULL;
	return (1);
}
