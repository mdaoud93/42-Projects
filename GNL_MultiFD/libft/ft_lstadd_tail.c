/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:47:34 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/21 16:07:26 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_tail(t_list **alst, t_list *node)
{
	t_list	*temp;

	temp = *alst;
	if (!*alst)
	{
		*alst = node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}
