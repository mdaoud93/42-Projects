/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tetri_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:19:44 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/08 16:04:20 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_tetri(t_tetri *t)
{
	int		x;

	x = 0;
	while (x < t->height)
	{
		free(t->shape[x]);
		t->shape[x] = NULL;
		x++;
	}
	free(t->start);
	t->start = NULL;
	free(t->shape);
	t->shape = NULL;
}

void		free_tetri_array(t_tetri **tetris)
{
	int		i;

	i = 0;
	while (tetris[i] != NULL)
	{
		free_tetri(tetris[i]);
		free(tetris[i]);
		tetris[i] = NULL;
		i++;
	}
}
