/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_flush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:52:11 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 13:40:10 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	buff_flush(t_pf_arg *arg)
{
	if ((write(arg->fd, arg->buff, arg->it)) < 0)
		return ;
	arg->it = 0;
}
