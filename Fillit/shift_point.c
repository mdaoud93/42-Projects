/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:43:03 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

void		shift_point(int dim, t_point *point)
{
	if (point->y < dim - 1)
		point->y++;
	else
	{
		point->x++;
		point->y = 0;
	}
}
