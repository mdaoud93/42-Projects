/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:59:09 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/10 13:56:06 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*temp;

	temp = ptr;
	while (n)
	{
		*temp = (unsigned char)c;
		temp++;
		n--;
	}
	return (ptr);
}
