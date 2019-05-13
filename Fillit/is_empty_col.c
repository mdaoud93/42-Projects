/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:44:08 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_empty_col(int col, int array[DIM][DIM])
{
	int		i;

	i = 0;
	while (i < DIM)
	{
		if (array[i][col])
			return (0);
		i++;
	}
	return (1);
}
