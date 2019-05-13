/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:44:20 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/08 16:03:17 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_int_board(int ***board, int dim)
{
	int		i;

	i = 0;
	while (i < dim)
	{
		free((*board)[i]);
		((*board)[i]) = NULL;
		i++;
	}
	free(*board);
	*board = NULL;
}

int			solve(t_tetri **tetris, int count)
{
	int		ind;
	int		dim;
	int		**board;

	dim = ceil_sqrt(count * 4);
	board = create_board(dim);
	if (board == NULL)
		return (-1);
	ind = 0;
	while ((solve_board(board, dim, tetris, ind)) == 0)
	{
		free_int_board(&board, dim);
		dim++;
		board = create_board(dim);
		if (board == NULL)
			return (-1);
	}
	print_board(dim, tetris);
	free_int_board(&board, dim);
	return (1);
}
