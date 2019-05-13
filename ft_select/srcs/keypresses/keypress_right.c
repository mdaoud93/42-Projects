/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 23:32:52 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:00:32 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_right(void)
{
	t_list	*cur_pos;

	cur_pos = get_cursor_pos();
	cur_pos->status &= ~UNDERLINED;
	cur_pos->next->status |= UNDERLINED;
}
