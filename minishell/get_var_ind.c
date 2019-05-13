/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:57:09 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:58 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Returns the index of the environmet variable pointed by "env_var".
** Returns -1 if the variable doesn't exit.
*/

int			get_env_ind(char *env_var, char **env_list)
{
	int		i;
	char	*find;

	i = 0;
	find = ft_strjoin(env_var, "=", 0);
	while (env_list[i] != NULL)
	{
		if (ft_strstr(env_list[i], find) == env_list[i])
		{
			free(find);
			return (i);
		}
		i++;
	}
	free(find);
	return (-1);
}
