/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:15:46 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:39:52 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "minishell.h"

static void		init_shell(t_shell *shell, char **environ)
{
	char	**env;
	int		count;

	count = 0;
	while (environ[count] != NULL)
		count++;
	if ((env = malloc(sizeof(char *) * (count + 1))) == NULL)
		exit(1);
	env[count] = NULL;
	count = 0;
	while (environ[count] != NULL)
	{
		if ((env[count] = ft_strdup(environ[count])) == NULL)
		{
			while (count-- > 0)
				free(env[count]);
			free(env);
			exit(1);
		}
		count++;
	}
	shell->env = env;
}

int				main(int argc, char **argv, char **environ)
{
	t_shell		shell;

	(void)argc;
	(void)argv;
	init_shell(&shell, environ);
	if (shell.env == NULL)
		return (0);
	signal(SIGINT, handler_sigint_shell);
	while (1)
	{
		display_prompt();
		process_input(&shell);
	}
	return (0);
}
