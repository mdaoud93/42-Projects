/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:52:53 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:08 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void				free_shell(t_shell *shell)
{
	size_t	i;

	if (shell->env != NULL)
	{
		i = 0;
		while (shell->env[i] != NULL)
		{
			free(shell->env[i]);
			i++;
		}
		free(shell->env);
	}
	if (shell->cmd != NULL)
	{
		i = 0;
		while (shell->cmd[i] != NULL)
		{
			free(shell->cmd[i]);
			i++;
		}
		free(shell->cmd);
	}
}
