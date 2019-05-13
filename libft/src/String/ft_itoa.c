/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:21:24 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/14 12:47:09 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*convert(int n, int len, int neg)
{
	char	*retval;
	int		i;
	int		size;

	size = len + neg + 1;
	if (!(retval = malloc(size * sizeof(char))))
		return (NULL);
	retval[size - 1] = '\0';
	i = len - 1;
	if (neg)
	{
		retval[0] = '-';
		i = len;
	}
	while (n)
	{
		retval[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (retval);
}

char			*ft_itoa(int n)
{
	int		neg;
	int		temp;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	neg = 0;
	len = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	temp = n;
	while (temp)
	{
		len++;
		temp /= 10;
	}
	return (convert(n, len, neg));
}
