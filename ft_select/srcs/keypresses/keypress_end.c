/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:59:57 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 15:59:59 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_end(void)
{
	t_list	*cursor_pos;

	cursor_pos = get_cursor_pos();
	cursor_pos->status &= ~UNDERLINED;
	g_sel->lst->prev->status |= UNDERLINED;
}
