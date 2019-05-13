/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 01:27:09 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:15:49 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>
#include <sys/ioctl.h>

static void		handler_sigint(int signo)
{
	if (signo == SIGINT)
	{
		restore_default_conf();
		exit(EXIT_SUCCESS);
	}
}

static void		handler_sigwinch(int signo)
{
	if (signo == SIGWINCH)
	{
		display_list();
	}
}

static void		handler_sigtstp(int signo)
{
	if (signo == SIGTSTP)
	{
		restore_default_conf();
		signal(SIGTSTP, SIG_DFL);
		ioctl(g_sel->fd, TIOCSTI, "\x1A");
	}
}

static void		handler_sigcont(int signo)
{
	if (signo == SIGCONT)
	{
		init_term();
		init_signal_handlers();
		display_list();
	}
}

void			init_signal_handlers(void)
{
	signal(SIGINT, handler_sigint);
	signal(SIGWINCH, handler_sigwinch);
	signal(SIGTSTP, handler_sigtstp);
	signal(SIGCONT, handler_sigcont);
}
