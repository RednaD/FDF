/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:11:04 by arusso            #+#    #+#             */
/*   Updated: 2017/11/14 17:46:01 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str_src;
	char	*str_dest;

	i = 0;
	str_src = (char*)src;
	str_dest = (char*)dest;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		if (str_src[i] == (char)c)
			return (&str_dest[i + 1]);
		i++;
	}
	return (NULL);
}
