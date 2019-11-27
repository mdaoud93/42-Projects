/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:58:21 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/16 12:10:56 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*retval;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (!(retval = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		retval[i] = s[start];
		start++;
		i++;
	}
	retval[i] = '\0';
	return (retval);
}
