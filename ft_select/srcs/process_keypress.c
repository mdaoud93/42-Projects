/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:17:03 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:18:03 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			process_keypress(unsigned int key_val)
{
	if (key_val == RET_KEY)
		return (1);
	else if (key_val == ESC_KEY)
		ft_exit(NULL, 1, EXIT_SUCCESS);
	else if (key_val == SPCE_KEY)
		keypress_space();
	else if (key_val == DEL_KEY || key_val == BCKSPCE_KEY)
		keypress_del();
	else if (key_val == UP_KEY)
		keypress_up();
	else if (key_val == DOWN_KEY)
		keypress_down();
	else if (key_val == RIGHT_KEY)
		keypress_right();
	else if (key_val == LEFT_KEY)
		keypress_left();
	else if (key_val == HOME_KEY)
		keypress_home();
	else if (key_val == END_KEY)
		keypress_end();
	return (0);
}
