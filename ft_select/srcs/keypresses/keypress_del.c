/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:59:46 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 15:59:52 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			keypress_del(void)
{
	t_list	*to_remove;

	if (g_sel->argc == 1)
		ft_exit(NULL, 1, EXIT_SUCCESS);
	to_remove = get_cursor_pos();
	if (to_remove == g_sel->lst)
		g_sel->lst = to_remove->next;
	to_remove->next->status |= UNDERLINED;
	to_remove->prev->next = to_remove->next;
	to_remove->next->prev = to_remove->prev;
	free(to_remove);
	g_sel->argc--;
}
