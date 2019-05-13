/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_home.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:59:34 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 15:59:41 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_home(void)
{
	t_list	*cursor_pos;

	cursor_pos = get_cursor_pos();
	cursor_pos->status &= ~UNDERLINED;
	g_sel->lst->status |= UNDERLINED;
}
