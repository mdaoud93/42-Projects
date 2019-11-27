/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:57:46 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/16 12:09:35 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*retval;
	int		it;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	it = 0;
	if ((retval = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (s[it])
	{
		retval[it] = f(s[it]);
		it++;
	}
	retval[it] = '\0';
	return (retval);
}
