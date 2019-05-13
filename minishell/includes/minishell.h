/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:18:39 by mdaoud            #+#    #+#             */
/*   Updated: 2019/03/06 14:21:11 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# define RED "\033[1;31m"
# define RES_COL "\033[0m"
# define GREEN "\033[1;32m"

typedef struct	s_shell
{
	char	**cmd;
	char	**env;
}				t_shell;

void			dispatch_env_cmd(char **cmd, t_shell *shell);
void			builtin_cd(char **cmd, t_shell *shell);
void			builtin_env(char **env);
void			builtin_setenv(char **cmd, t_shell *shell);
void			builtin_echo(char **cmd);
void			process_cmd(char **cmd, t_shell *shell);
void			builtin_unsetenv(char **cmd, t_shell *shell);
void			display_prompt(void);
void			free_shell(t_shell *shell);
void			process_input(t_shell *shell);
void			handler_sigint_cmd(int signo);
void			handler_sigint_shell(int signo);
size_t			get_count(char **tab);
void			add_env_var(t_shell *shell, char *key, char *val);
void			free_string_array(char **tab);
int				check_cmd_format(char **cmd, size_t param_num);
int				get_env_ind(char *env_var, char **env_list);
char			*get_env_value(char *key, char **env);
void			change_directory(char *path, t_shell *shell, int print_dir);

#endif
