/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:59:05 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 15:59:16 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_down(void)
{
	t_list	*cur_pos;
	size_t	i;

	cur_pos = get_cursor_pos();
	i = 0;
	cur_pos->status &= ~UNDERLINED;
	while (i++ < g_sel->col_count)
		cur_pos = cur_pos->next;
	cur_pos->status |= UNDERLINED;
}
