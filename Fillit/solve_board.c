/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:49:37 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/08 16:00:52 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve_board(int **board, int dim, t_tetri **tetris, int index)
{
	t_point		*pos;

	pos = create_point(0, 0);
	if (pos == NULL)
		return (0);
	if (tetris[index] == NULL)
	{
		free(pos);
		return (1);
	}
	while ((place_tetri(board, dim, tetris[index], pos)) == 1)
	{
		if ((solve_board(board, dim, tetris, index + 1)) == 1)
			return (1);
		remove_tetri(board, tetris[index]);
		shift_point(dim, pos);
	}
	free(pos);
	return (0);
}
