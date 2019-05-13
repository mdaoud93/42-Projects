/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:47:27 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/26 13:47:53 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strreplace(char *str, char from, char to)
{
	int		i;
	char	*retval;

	i = 0;
	retval = ft_strdup(str);
	while (str[i])
	{
		if (str[i] == from)
			retval[i] = to;
		else
			retval[i] = str[i];
		i++;
	}
	return (retval);
}
