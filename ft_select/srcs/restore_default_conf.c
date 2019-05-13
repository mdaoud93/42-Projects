/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_default_conf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:08:25 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:18:27 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			restore_default_conf(void)
{
	g_sel->term->c_lflag |= (ICANON | ECHO);
	tcsetattr(g_sel->fd, 0, g_sel->oldterm);
	tputs(tgetstr("te", NULL), 1, tputs_char);
	tputs(tgetstr("ve", NULL), 1, tputs_char);
}
