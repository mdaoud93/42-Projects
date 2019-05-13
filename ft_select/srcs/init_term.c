/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 02:00:54 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:50:21 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>

static void		exit_term_error(char *message)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(EXIT_FAILURE);
}

/*
** Checks if the device is a terminal.
** Save the terminal info in 'term' variable for further moification.
** Save the terminal info in 'oldterm' variable to restore it at the end.
*/

static void		init_terminfo(void)
{
	int		ret;
	char	*term_type;
	char	buf[2048];

	if ((ret = isatty(STDIN_FILENO)) < 0)
		exit_term_error("Device is not a tty");
	if ((g_sel->fd = open(ttyname(STDIN_FILENO), O_RDWR)) == -1)
		exit_term_error("ttyname");
	term_type = getenv("TERM");
	if (term_type == NULL)
		exit_term_error("TERM environment variable is not set");
	ret = tgetent(buf, term_type);
	if (ret == 0)
		exit_term_error("Can't find TERM entry in terminfo base");
	if (ret == -1)
		exit_term_error("terminfo database could not be found");
	if ((g_sel->term = malloc(sizeof(t_termios))) == NULL)
		exit_term_error("malloc");
	if ((g_sel->oldterm = malloc(sizeof(t_termios))) == NULL)
		exit_term_error("malloc");
	if ((tcgetattr(g_sel->fd, g_sel->term)) < 0)
		exit_term_error("tcgetattr");
	if ((tcgetattr(g_sel->fd, g_sel->oldterm)) < 0)
		exit_term_error("tcgetattr");
}

/*
** Modify the termio structure to our needs.
** Put the termios in NON-CANNONICAL mode (take input one character at a time).
** Remove "ECHO" flag (don't print the input character).
** ti: command to enable the cursor move nonsequentially around the screen.
** vi: command to make the cursor invisible.
** Get the width and height of the terminal window.
*/

static void		fill_terminfo(void)
{
	struct winsize w;

	g_sel->term->c_lflag &= !ICANON;
	g_sel->term->c_lflag &= !ECHO;
	g_sel->term->c_lflag |= ISIG;
	g_sel->term->c_cc[VMIN] = 1;
	g_sel->term->c_cc[VTIME] = 0;
	tputs(tgetstr("ti", NULL), 1, tputs_char);
	tputs(tgetstr("vi", NULL), 1, tputs_char);
	tcsetattr(g_sel->fd, 0, g_sel->term);
	if ((ioctl(g_sel->fd, TIOCGWINSZ, &w)) < 0)
		ft_exit("ioctl", 1, EXIT_FAILURE);
	g_sel->win_height = w.ws_row;
	g_sel->win_width = w.ws_col;
}

void			init_term(void)
{
	init_terminfo();
	fill_terminfo();
}
