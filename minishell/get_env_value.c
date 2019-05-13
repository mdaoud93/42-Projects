/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 22:04:26 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:39:35 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*get_env_value(char *key, char **env)
{
	size_t		ind;
	char		*val;

	if ((ind = get_env_ind(key, env)) == -1)
		return (ft_strdup(""));
	val = ft_strchr(env[ind], '=');
	return (ft_strdup(val + 1));
}
