/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:29:52 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			**create_board(int dimension)
{
	int		**board;
	int		i;
	int		j;

	if ((board = malloc(dimension * sizeof(int *))) == NULL)
		return (NULL);
	i = 0;
	while (i < dimension)
	{
		board[i] = malloc(dimension * sizeof(int *));
		if (board[i] == NULL)
			return (NULL);
		j = 0;
		while (j < dimension)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}
