/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:51:35 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:16:38 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

t_list			*lst_append(t_list *lst, char *name)
{
	t_list	*node;
	t_list	*tmp;

	if ((node = malloc(sizeof(t_list))) == NULL)
		ft_exit("malloc", 0, EXIT_FAILURE);
	ft_strcpy(node->name, name);
	if (lst == NULL)
	{
		node->next = node;
		node->prev = node;
		return (node);
	}
	tmp = lst->prev;
	tmp->next = node;
	node->next = lst;
	node->prev = tmp;
	lst->prev = node;
	return (lst);
}
