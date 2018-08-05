/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:48:21 by arusso            #+#    #+#             */
/*   Updated: 2017/12/03 22:35:48 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t i;

	if (!(tofind[0]))
		return ((char*)str);
	i = 0;
	while (str[i] && i + ft_strlen((char*)tofind) <= (size_t)len)
	{
		if (ft_strncmp(&str[i], tofind, ft_strlen((char*)tofind)) == 0)
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
