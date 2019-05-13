/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_key_presses.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:30:12 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:12:54 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			init_buf(char buf[])
{
	size_t	i;

	i = 0;
	while (i < 5)
	{
		buf[i] = 0;
		i++;
	}
}

void				detect_key_presses(void)
{
	char	buf[5];
	int		ret;

	init_buf(buf);
	while ((ret = read(0, buf, 4)) != 0)
	{
		if (ret < 0)
			ft_exit("read", 1, EXIT_FAILURE);
		else
		{
			ret = process_keypress(*(unsigned int *)buf);
			if (ret == 1)
				break ;
			display_list();
			init_buf(buf);
			continue ;
		}
	}
}
