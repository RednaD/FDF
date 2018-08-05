/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:02:09 by arusso            #+#    #+#             */
/*   Updated: 2017/11/22 13:32:15 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	len;
	char			*dest;

	if (n == -2147483648)
		return ((char*)ft_strdup("-2147483648"));
	if (n == -0)
		return ((char*)ft_strdup("0"));
	len = ft_intlen(n);
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
	{
		dest[0] = '-';
		n = n * -1;
	}
	dest[len] = '\0';
	len--;
	while (n)
	{
		dest[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (dest);
}
