/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:14:14 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:08 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Removes the environmet variable at index "ind".
** Reallocs the shell's environment array.
*/

static void			remove_env_var(t_shell *shell, int ind)
{
	char	**new_env;
	int		count;
	size_t	i;

	count = get_count(shell->env);
	if ((new_env = malloc(sizeof(char *) * (count))) == NULL)
		exit(1);
	i = 0;
	count = 0;
	while (shell->env[count] != NULL)
	{
		if (count == ind)
		{
			free(shell->env[count]);
			count++;
			continue ;
		}
		new_env[i++] = shell->env[count++];
	}
	new_env[i] = NULL;
	free(shell->env);
	shell->env = new_env;
}

/*
** Checks that the command is well formatted.
** Removes the environment variable specified in cmd if it exists.
** Does nothing if the string given does not exist.
*/

void				builtin_unsetenv(char **cmd, t_shell *shell)
{
	int		ind;

	if (check_cmd_format(cmd, 1) == -1)
	{
		ft_printf("usage: unsetenv variable_name\n");
		return ;
	}
	if ((ind = get_env_ind(cmd[1], shell->env)) == -1)
		return ;
	remove_env_var(shell, ind);
}
