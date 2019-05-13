/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:44:42 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			valid_input(char *str)
{
	int		i;
	int		count;

	count = 0;
	while (*str)
	{
		i = 0;
		while (i < 4)
		{
			if (*str != '.' && *str != '#')
				return (0);
			if (*str == '#')
				count++;
			i++;
			str++;
		}
		if (*str != '\n')
			return (0);
		str++;
	}
	return (count == 4);
}
