/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:35:38 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*create_point(int x, int y)
{
	t_point		*point;

	if ((point = malloc(sizeof(t_point))) == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}
