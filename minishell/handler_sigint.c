/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sigint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:46:50 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:39:00 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"
#include "ft_printf.h"

/*
** Function to handle the (Ctrl + C) when a process is being executed.
** It will kill the running process and give command back to the shell.
*/

void			handler_sigint_cmd(int signo)
{
	if (signo == SIGINT)
		ft_printf("\n");
}

/*
** Function to handle the SIGINT signal (Ctrl + C) when waiting for a command.
** If Ctrl + C is pressed while typing a command, the command will be discarded
**	and the prompt will reappear.
*/

void			handler_sigint_shell(int signo)
{
	if (signo == SIGINT)
	{
		ft_printf("\n");
		display_prompt();
	}
}
