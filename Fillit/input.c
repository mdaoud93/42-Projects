/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:28:06 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/01 15:46:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		**input(int fd, int *count)
{
	char	buff[READ_BUFF_SIZE];
	int		flag;
	int		retval;
	t_tetri	**tetris;

	if ((tetris = malloc((MAX_TETRIMINIO + 1) * sizeof(t_tetri *))) == NULL)
		return (NULL);
	while ((retval = read(fd, buff, READ_BUFF_SIZE - 1)) > 0)
	{
		flag = 0;
		buff[retval] = '\0';
		if (!valid_input(buff) || *count >= MAX_TETRIMINIO)
		{
			tetris[*count] = NULL;
			free_tetri_array(tetris);
			return (NULL);
		}
		flag = newline(fd);
		if ((tetris[(*count)++] = create_tetris(buff)) == NULL)
			return (NULL);
	}
	if (*count == 0 || (flag && retval == 0))
		return (NULL);
	tetris[*count] = NULL;
	return (tetris);
}
