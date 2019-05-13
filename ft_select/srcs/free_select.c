/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:37:29 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:14:34 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <stdlib.h>

void			free_select(void)
{
	t_list	*tmp;
	size_t	i;

	if (g_sel->term)
		free(g_sel->term);
	if (g_sel->oldterm)
		free(g_sel->oldterm);
	i = 0;
	while (i < g_sel->argc)
	{
		tmp = g_sel->lst->next;
		free(g_sel->lst);
		g_sel->lst = tmp;
		i++;
	}
	free(g_sel);
	g_sel = NULL;
}
