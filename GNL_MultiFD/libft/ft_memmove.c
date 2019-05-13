/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:52:04 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/14 15:06:54 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Optimisation with uni64_t needed
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	temp = dest;
	if (src == dest)
		return (dest);
	if (src < dest && src + n > dest)
	{
		temp = (char *)temp + n;
		src = (char *)src + n;
		while (n--)
			*(char *)--temp = *(const char *)--src;
		return (dest);
	}
	while (n--)
		*(char *)temp++ = *(char *)src++;
	return (dest);
}
