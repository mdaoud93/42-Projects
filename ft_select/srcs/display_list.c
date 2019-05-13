/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:07:15 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:26:07 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>

/*
** Prints the argument name in different ways depending on their status.
** (See the "ft_select.h" for further information)
*/

static void			display_name(t_list *element, int pad)
{
	if (element->status == REMOVED)
		return ;
	if (element->status == NORMAL)
	{
		ft_dprintf(g_sel->fd, "%s", element->name);
		ft_dprintf(g_sel->fd, "%-*s",\
			(int)(pad - ft_strlen(element->name)), " ");
		return ;
	}
	if (element->status & UNDERLINED)
	{
		ft_dprintf(g_sel->fd, "%s", COL_CYAN);
		tputs(tgetstr("us", NULL), 1, tputs_char);
	}
	if (element->status & SELECTED)
		tputs(tgetstr("mr", NULL), 1, tputs_char);
	ft_dprintf(g_sel->fd, "%s", element->name);
	if (element->status & UNDERLINED)
		tputs(tgetstr("ue", NULL), 1, tputs_char);
	if (element->status & SELECTED)
		tputs(tgetstr("me", NULL), 1, tputs_char);
	ft_dprintf(g_sel->fd, "%s", COL_RES);
	ft_dprintf(g_sel->fd, "%*c", (int)(pad - ft_strlen(element->name)), ' ');
}

/*
** Configures the number of lines/columns in which the arguments are displayed.
** The arguments will be displayed in a grid-like way.
*/

static void			config_dimensions(void)
{
	size_t	padded_arg;
	size_t	mod;

	padded_arg = g_sel->max_arg_len + 2;
	g_sel->col_count = g_sel->win_width / padded_arg;
	if (g_sel->col_count == 0)
		g_sel->col_count = 1;
	g_sel->row_count = g_sel->argc / g_sel->col_count;
	mod = g_sel->argc % g_sel->col_count;
	if (mod > 0)
		g_sel->row_count++;
}

static void			detect_winsize_changes(void)
{
	struct winsize w;

	if ((ioctl(g_sel->fd, TIOCGWINSZ, &w)) < 0)
		ft_exit("ioctl", 1, EXIT_FAILURE);
	if (g_sel->win_height != w.ws_row || g_sel->win_width != w.ws_col)
	{
		g_sel->win_height = w.ws_row;
		g_sel->win_width = w.ws_col;
	}
}

/*
** Clears the screen.
** Loops through all arguments and prints each one depending of their status.
*/

void				display_list(void)
{
	t_list	*tmp;
	size_t	col;
	size_t	i;

	if (g_sel == NULL)
		return ;
	tputs(tgetstr("cl", NULL), 1, tputs_char);
	detect_winsize_changes();
	config_dimensions();
	tmp = g_sel->lst;
	i = 0;
	col = 1;
	while (i++ < g_sel->argc)
	{
		display_name(tmp, g_sel->max_arg_len);
		ft_dprintf(g_sel->fd, (col == g_sel->col_count ? "\n" : " "));
		col = (col == g_sel->col_count ? 1 : col + 1);
		tmp = tmp->next;
	}
}
