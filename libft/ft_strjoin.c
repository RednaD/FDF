/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:10:13 by arusso            #+#    #+#             */
/*   Updated: 2018/08/16 17:06:31 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dest;

	if (!s1 || !s2)
		return (NULL);
	if (!(dest = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
		return (NULL);
	dest = ft_strcat(dest, s1);
	dest = ft_strcat(dest, s2);
	return (dest);
}
