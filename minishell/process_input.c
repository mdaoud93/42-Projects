/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:41:43 by mdaoud            #+#    #+#             */
/*   Updated: 2019/03/06 14:20:00 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <limits.h>

/*
** Removes leading/trailling whitespaces/tabulations from the command.
*/

static void			trim_cmd(t_shell *shell)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (shell->cmd[i] != NULL)
	{
		temp = shell->cmd[i];
		shell->cmd[i] = ft_strreplace(shell->cmd[i], '\t', ' ');
		free(temp);
		temp = shell->cmd[i];
		shell->cmd[i] = ft_strtrim(temp);
		free(temp);
		i++;
	}
}

/*
** Replaces strings beginning with "$" sign with their corresponding
**	environemt variable.
** Replaces "~" strings with the value of the environment variable "HOME".
*/

static char			*parse_special_char(char *str, char **env_lst)
{
	char	*retval;

	if (str[0] == '$' && str[1] != '\0')
	{
		if (str[1] == '\0')
			return (ft_strdup("$"));
		else
			return (get_env_value(str + 1, env_lst));
	}
	retval = get_env_value("HOME", env_lst);
	if (str[1] != '\0')
		retval = ft_strjoin(retval, str + 1, 1);
	return (retval);
}

/*
** Takes a command after being split.
** If a string contains '$' or '~' parse them using parse_special_char().
*/

static char			**parse_cmd_param(char **cmd, t_shell *shell)
{
	size_t	count;
	char	*temp;

	count = 0;
	while (cmd[count] != NULL)
	{
		if (cmd[count][0] == '$' || cmd[count][0] == '~')
		{
			temp = cmd[count];
			cmd[count] = parse_special_char(cmd[count], shell->env);
			free(temp);
		}
		count++;
	}
	return (cmd);
}

/*
** Checks whether or not the input string is a builtin command.
** Dispatches the string to the appropriate function.
*/

static void			dispatch_cmd(char *cmd, t_shell *shell)
{
	char	**cmd_array;

	cmd_array = ft_strsplit(cmd, ' ');
	cmd_array = parse_cmd_param(cmd_array, shell);
	if (ft_strequ("exit", cmd_array[0]))
	{
		free_string_array(cmd_array);
		free_shell(shell);
		exit(0);
	}
	if (ft_strequ("env", cmd_array[0]) || ft_strequ("setenv", cmd_array[0]) \
			|| ft_strequ("unsetenv", cmd_array[0]))
		dispatch_env_cmd(cmd_array, shell);
	else if (ft_strequ("cd", cmd_array[0]))
		builtin_cd(cmd_array, shell);
	else if (ft_strequ("echo", cmd_array[0]))
		builtin_echo(cmd_array);
	else
		process_cmd(cmd_array, shell);
}

/*
** Function to get the input, split it into multiple commands if the
** ";" character is detected, store the commands in the "cmd" field of
** the "shell" structure, And finally execute each command consecutively.
*/

void				process_input(t_shell *shell)
{
	char	cmd[MAX_INPUT + 1];
	size_t	i;

	ft_bzero(cmd, MAX_INPUT + 1);
	if (read(0, cmd, MAX_INPUT) > 0)
	{
		if (cmd[ft_strlen(cmd) - 1] != '\n')
			ft_printf("\n");
		shell->cmd = ft_strsplit(cmd, ';');
		trim_cmd(shell);
		i = 0;
		while (shell->cmd[i] != NULL)
		{
			if (!ft_strequ("", shell->cmd[i]))
				dispatch_cmd(shell->cmd[i], shell);
			i++;
		}
		free_string_array(shell->cmd);
	}
	else
		ft_printf("\n");
}
