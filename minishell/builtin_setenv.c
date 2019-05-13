/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:14:16 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:08 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Sets the value of an existing environment variable at index "ind" to "val".
*/

static void		set_env_value(char **env_lst, size_t ind, char *key, char *val)
{
	free(env_lst[ind]);
	env_lst[ind] = ft_strjoin(key, "=", 0);
	env_lst[ind] = ft_strjoin(env_lst[ind], val, 1);
}

void			builtin_setenv(char **cmd, t_shell *shell)
{
	int		var_ind;

	if (check_cmd_format(cmd, 0) == -1 && check_cmd_format(cmd, 2) == -1)
	{
		ft_printf("usage: setenv key value\n");
		return ;
	}
	if (cmd[1] == NULL)
	{
		builtin_env(shell->env);
		return ;
	}
	var_ind = get_env_ind(cmd[1], shell->env);
	if (var_ind == -1)
		add_env_var(shell, cmd[1], cmd[2]);
	else
		set_env_value(shell->env, var_ind, cmd[1], cmd[2]);
}
