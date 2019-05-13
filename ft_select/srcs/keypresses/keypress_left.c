/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:00:07 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:12:19 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_left(void)
{
	t_list	*cur_pos;

	cur_pos = get_cursor_pos();
	cur_pos->status &= ~UNDERLINED;
	cur_pos->prev->status |= UNDERLINED;
}
