/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:00:37 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:00:42 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_up(void)
{
	t_list	*cur_pos;
	size_t	i;

	cur_pos = get_cursor_pos();
	i = 0;
	cur_pos->status &= ~UNDERLINED;
	while (i++ < g_sel->col_count)
		cur_pos = cur_pos->prev;
	cur_pos->status |= UNDERLINED;
}
