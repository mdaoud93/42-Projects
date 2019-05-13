/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:25:14 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:08 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t			get_count(char **tab)
{
	size_t		count;

	count = 0;
	while (tab[count] != NULL)
		count++;
	return (count);
}
