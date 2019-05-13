/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 23:27:27 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:15:01 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list			*get_cursor_pos(void)
{
	t_list	*ret;
	size_t	i;

	ret = g_sel->lst;
	i = 0;
	while (i < g_sel->argc)
	{
		if (ret->status & UNDERLINED)
			return (ret);
		ret = ret->next;
		i++;
	}
	return (NULL);
}
