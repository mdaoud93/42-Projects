/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:46:42 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/16 12:09:52 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	it;
	char			*retval;

	if (s == NULL)
		return (NULL);
	it = 0;
	if ((retval = malloc((ft_strlen(s) + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (s[it])
	{
		retval[it] = f(it, s[it]);
		it++;
	}
	retval[it] = '\0';
	return (retval);
}
