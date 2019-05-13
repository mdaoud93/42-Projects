/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:47:57 by mdaoud            #+#    #+#             */
/*   Updated: 2018/12/03 09:48:02 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_malloc_2d(int height, int width)
{
	int		**tab;
	int		i;

	if (height <= 0 || width <= 0)
		return (NULL);
	tab = malloc(height * sizeof(int *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		tab[i] = malloc(width * sizeof(int));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}
