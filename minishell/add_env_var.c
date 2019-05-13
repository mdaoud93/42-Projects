/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 03:30:49 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:08 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Reallocs the env to add a new variable.
** Adds the string key=value to the new list of the environment variables.
*/

void			add_env_var(t_shell *shell, char *key, char *val)
{
	size_t	count;
	char	**new_env;

	count = get_count(shell->env);
	if ((new_env = malloc(sizeof(char *) * (count + 2))) == NULL)
		exit(1);
	new_env[count + 1] = NULL;
	count = 0;
	while (shell->env[count] != NULL)
	{
		new_env[count] = shell->env[count];
		count++;
	}
	free(shell->env);
	new_env[count] = ft_strjoin(key, "=", 0);
	new_env[count] = ft_strjoin(new_env[count], val, 1);
	shell->env = new_env;
}
