/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 00:52:22 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:08 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>
#include <limits.h>

static void		set_oldpwd(char *val, char **env)
{
	size_t		ind;
	char		*var;

	ind = get_env_ind("OLDPWD", env);
	free(env[ind]);
	var = ft_strjoin("OLDPWD=", val, 0);
	env[ind] = var;
}

static void		set_pwd(char *val, t_shell *shell)
{
	size_t		ind;
	char		*var;
	char		curr_dir[PATH_MAX];

	if ((ind = get_env_ind("PWD", shell->env)) == -1)
	{
		getcwd(curr_dir, PATH_MAX);
		add_env_var(shell, "PWD", curr_dir);
		return ;
	}
	free(shell->env[ind]);
	var = ft_strjoin("PWD=", val, 0);
	shell->env[ind] = var;
}

/*
** Changes the current working directory.
** Updates the environment variables "PWD" and "OLDPWD".
** In case of error, prints the appropriate error message.
*/

void			change_directory(char *path, t_shell *shell, int print_dir)
{
	char	old_dir[PATH_MAX];

	if (print_dir)
		ft_printf("%s\n", path);
	getcwd(old_dir, PATH_MAX);
	if (chdir(path) == -1)
	{
		if ((access(path, F_OK) == -1))
			ft_printf("cd: no such file or directory: %s\n", path);
		else if ((access(path, R_OK) == -1))
			ft_printf("cd: permission denied: %s\n", path);
		else
			ft_printf("cd: not a directory: %s\n", path);
		return ;
	}
	set_oldpwd(old_dir, shell->env);
	set_pwd(path, shell);
}
