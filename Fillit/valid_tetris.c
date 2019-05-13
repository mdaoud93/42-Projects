/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:16:00 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/08 16:04:30 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_tetris(int array[DIM][DIM])
{
	int count;
	int	x;
	int	y;

	count = 0;
	x = -1;
	while (++x < DIM)
	{
		y = -1;
		while (++y < DIM)
		{
			if (array[x][y])
			{
				if (x - 1 >= 0 && array[x - 1][y])
					count++;
				if (x + 1 < DIM && array[x + 1][y])
					count++;
				if (y - 1 >= 0 && array[x][y - 1])
					count++;
				if (y + 1 < DIM && array[x][y + 1])
					count++;
			}
		}
	}
	return (count == 6 || count == 8);
}
