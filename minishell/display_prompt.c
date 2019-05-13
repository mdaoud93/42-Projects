/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:49:56 by mdaoud            #+#    #+#             */
/*   Updated: 2019/02/13 11:38:34 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"
#include <limits.h>

void			display_prompt(void)
{
	char		cwd[PATH_MAX];
	char		*dir_name;
	int			root_dir;

	getcwd(cwd, PATH_MAX);
	root_dir = !ft_strequ("/", cwd);
	dir_name = ft_strrchr(cwd, '/');
	if (dir_name == NULL)
		dir_name = cwd;
	ft_printf("%s➜  %s%s%s ", GREEN, RED, dir_name + root_dir, RES_COL);
}
