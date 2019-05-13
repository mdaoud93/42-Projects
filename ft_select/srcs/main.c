/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:29:25 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 16:43:32 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"
#include <sys/ioctl.h>

/*
** Create the doubly-linked list with the arguments of the program.
*/

static void		init_list(int argc, char **argv)
{
	int		i;
	size_t	max_len;

	g_sel = malloc(sizeof(t_select));
	i = 0;
	max_len = 0;
	g_sel->lst = NULL;
	while (i < argc)
	{
		g_sel->lst = lst_append(g_sel->lst, argv[i]);
		if (ft_strlen(argv[i]) > max_len)
			max_len = ft_strlen(argv[i]);
		i++;
	}
	g_sel->max_arg_len = max_len;
	g_sel->argc = argc;
	g_sel->selected_arg_count = 0;
}

static void		init_status(void)
{
	t_list	*tmp;

	g_sel->lst->status = NORMAL | UNDERLINED;
	tmp = g_sel->lst->next;
	while (tmp != g_sel->lst)
	{
		tmp->status = NORMAL;
		tmp = tmp->next;
	}
}

int				main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("usage: ./ft_select arg1 [arg2] [arg2]..\n");
		return (0);
	}
	init_signal_handlers();
	init_list(argc - 1, argv + 1);
	init_term();
	init_status();
	display_list();
	detect_key_presses();
	restore_default_conf();
	display_selected();
	return (0);
}
