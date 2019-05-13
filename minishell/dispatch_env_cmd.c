/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_env_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:58:55 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:12 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"

void			dispatch_env_cmd(char **cmd, t_shell *shell)
{
	if (ft_strequ("env", cmd[0]))
		builtin_env(shell->env);
	else if (ft_strequ("setenv", cmd[0]))
		builtin_setenv(cmd, shell);
	else if (ft_strequ("unsetenv", cmd[0]))
		builtin_unsetenv(cmd, shell);
	free_string_array(cmd);
}
