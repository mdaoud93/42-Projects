/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:03:54 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 12:12:23 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

static void			fork_execve(char **cmd, t_shell *shell)
{
	pid_t	cpid;

	if ((cpid = fork()) == -1)
	{
		ft_printf("Error: fork failed to create a new process\n");
		free_string_array(cmd);
		free_shell(shell);
		exit(1);
	}
	else if (cpid == 0)
		execve(cmd[0], cmd, shell->env);
	wait(&cpid);
}

static char			*get_cmd_bin_path(char **cmd, t_shell *shell)
{
	char	*path;
	char	*token;
	char	*bin_cmd;

	path = get_env_value("PATH", shell->env);
	token = ft_strtok(path, ":");
	while (token != NULL)
	{
		bin_cmd = ft_strjoin(token, "/", 0);
		bin_cmd = ft_strjoin(bin_cmd, cmd[0], 1);
		if (access(bin_cmd, F_OK) != -1)
		{
			free(path);
			return (bin_cmd);
		}
		free(bin_cmd);
		token = ft_strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

/*
** Replaces the builtin command with its full path
** Example: ls -l ~/Documents --> /bin/ls -l ~/Documents
** If the process has no execution rights on the binary file, return -1.
** If the process has execution rights on the binary, call fork_execve.
*/

static void			run_builtin_cmd(char *path, char **cmd, t_shell *shell)
{
	if (access(path, X_OK) == -1)
	{
		free(path);
		ft_printf("minishell: permission denied: %s\n", cmd[0]);
		return ;
	}
	free(cmd[0]);
	cmd[0] = path;
	fork_execve(cmd, shell);
}

void				process_cmd(char **cmd, t_shell *shell)
{
	struct stat		f_stat;
	char			*bin_cmd;

	signal(SIGINT, handler_sigint_cmd);
	if (lstat(cmd[0], &f_stat) != -1)
	{
		if ((f_stat.st_mode & S_IFMT) == S_IFDIR)
		{
			change_directory(cmd[0], shell, 0);
			free_string_array(cmd);
			return ;
		}
		else
		{
			run_builtin_cmd(ft_strdup(cmd[0]), cmd, shell);
			free_string_array(cmd);
			return ;
		}
	}
	if ((bin_cmd = get_cmd_bin_path(cmd, shell)) != NULL)
		run_builtin_cmd(bin_cmd, cmd, shell);
	else
		ft_printf("minishell: command not found: %s\n", cmd[0]);
	free_string_array(cmd);
	return ;
}
