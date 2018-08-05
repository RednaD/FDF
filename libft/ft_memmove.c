/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:21:56 by llefevre          #+#    #+#             */
/*   Updated: 2017/11/28 14:34:31 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*str_src;
	char		*str_dest;

	str_src = src;
	str_dest = dest;
	if (str_dest <= str_src || str_src >= (str_dest + len))
	{
		while (len--)
		{
			*str_dest++ = *str_src++;
		}
	}
	else
	{
		str_src = str_src + len - 1;
		str_dest = str_dest + len - 1;
		while (len--)
		{
			*str_dest = *str_src;
			str_dest--;
			str_src--;
		}
	}
	return (dest);
}
