/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:05:07 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		newline(int fd)
{
	char	buff[1];
	int		retval;

	retval = read(fd, buff, 1);
	if (retval < 0)
		return (-1);
	if (retval == 0)
		return (0);
	if (buff[0] != '\n')
		return (0);
	return (1);
}
