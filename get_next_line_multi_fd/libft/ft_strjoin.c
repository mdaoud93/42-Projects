/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:18:22 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/19 18:32:41 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*retval;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	retval = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*retval));
	if (!retval)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		retval[i++] = s1[j++];
	j = 0;
	while (s2[j])
		retval[i++] = s2[j++];
	retval[i] = '\0';
	if (n & 1)
		ft_strdel(&s1);
	if (n & 2)
		ft_strdel(&s2);
	return (retval);
}
