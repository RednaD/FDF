/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:38:16 by arusso            #+#    #+#             */
/*   Updated: 2017/11/18 16:29:50 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;
	int		length;

	if (!s)
		return (NULL);
	length = ft_strlen((char*)s);
	if (!(dest = (char*)malloc(sizeof(char) * (length) + 1)))
		return (NULL);
	i = 0;
	while (i < length)
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
