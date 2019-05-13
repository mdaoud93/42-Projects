/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_selected.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:14:21 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:14:22 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			display_selected(void)
{
	t_list	*tmp;
	size_t	i;

	tmp = g_sel->lst;
	i = 0;
	while (i < g_sel->argc)
	{
		if (tmp->status & SELECTED)
		{
			ft_dprintf(STDOUT_FILENO, "%s", tmp->name);
			g_sel->selected_arg_count--;
			if (g_sel->selected_arg_count > 0)
				ft_dprintf(STDOUT_FILENO, " ");
		}
		tmp = tmp->next;
		i++;
	}
}
