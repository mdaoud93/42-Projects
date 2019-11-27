/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expansions_parameter_plus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:05:41 by jmartel           #+#    #+#             */
/*   Updated: 2019/11/22 09:12:06 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_21.h"

/*
** sh_expansions_parameter_plus:
**					parameter Not Null		parameter Null		parameter Unset
**parameter:+word	substitute word			substitute null		substitute null
**parameter+word	substitute word			substitute word		substitute null
**
**	return Value:
**		SUCCESS : exp->res sucessfully filled
**		FAILURE : malloc error
*/

int			sh_expansions_parameter_plus(
	t_context *context, t_expansion *exp, char *format)
{
	char	*param;
	char	*word;
	int		ret;

	param = sh_expansions_parameter_get_param(context, exp);
	if ((ret = sh_expansions_parameter_get_word(context, exp, format, &word)))
		return (ret);
	if (!param)
		exp->res = ft_dy_str_new_str("");
	else if (!*param)
	{
		if (ft_strchr(format, ':'))
			exp->res = ft_dy_str_new_str("");
		else
			exp->res = ft_dy_str_new_str(word);
	}
	else
		exp->res = ft_dy_str_new_str(word);
	if (sh_verbose_expansion())
		ft_dprintf(2, "param : %s <> word : %s\n", param, word);
	if (word)
		ft_strdel(&word);
	if (!exp->res)
		return (sh_perror(SH_ERR1_MALLOC, "sh_expansions_"));
	return (SUCCESS);
}
