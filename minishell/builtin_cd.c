/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:40:38 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 12:27:35 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

/*
** If the "cd" is used with no OLDPWD variable,
**	OLDPWD is set to the current working directory.
*/

static void			repair_oldpwd(t_shell *shell)
{
	char	current_dir[PATH_MAX];

	if (get_env_ind("OLDPWD", shell->env) != -1)
		return ;
	getcwd(current_dir, PATH_MAX);
	add_env_var(shell, "OLDPWD", current_dir);
}

/*
** Checks if the "cd" command is well formatted.
** replaces special arguments such as "-" and "--" with their respective values
** Calls the function "change_directory()".
*/

void				builtin_cd(char **cmd, t_shell *shell)
{
	char	*path;
	int		print_dir;

	print_dir = 0;
	repair_oldpwd(shell);
	if (check_cmd_format(cmd, 0) == -1 && check_cmd_format(cmd, 1) == -1)
	{
		ft_printf("usage: cd directory\n");
		return ;
	}
	if (cmd[1] == NULL || ft_strequ("--", cmd[1]))
		path = get_env_value("HOME", shell->env);
	else if (ft_strequ("-", cmd[1]))
	{
		print_dir = 1;
		path = get_env_value("OLDPWD", shell->env);
	}
	else
		path = ft_strdup(cmd[1]);
	change_directory(path, shell, print_dir);
	free(path);
	free_string_array(cmd);
}
