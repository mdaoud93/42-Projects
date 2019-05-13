/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:28:04 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:46:43 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

void			ft_exit(char *message, int to_free, int exit_value)
{
	restore_default_conf();
	if (message != NULL)
		ft_dprintf(STDERR_FILENO, "Error: %s\n", message);
	if (to_free && g_sel != NULL)
		free_select();
	exit(exit_value);
}
