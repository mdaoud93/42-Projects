/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:52:43 by mdaoud            #+#    #+#             */
/*   Updated: 2019/04/02 14:06:15 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int			ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = ft_dprintf(1, format, ap);
	va_end(ap);
	return (ret);
}
