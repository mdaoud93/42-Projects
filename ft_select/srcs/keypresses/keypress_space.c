/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:00:18 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:00:22 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_space(void)
{
	t_list	*curr;

	curr = get_cursor_pos();
	curr->status &= ~UNDERLINED;
	if (curr->status & SELECTED)
	{
		curr->status &= ~SELECTED;
		g_sel->selected_arg_count--;
	}
	else
	{
		curr->status |= SELECTED;
		g_sel->selected_arg_count++;
	}
	curr->next->status |= UNDERLINED;
}
