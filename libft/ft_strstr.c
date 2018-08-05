/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:52:23 by arusso            #+#    #+#             */
/*   Updated: 2017/12/03 22:47:50 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	size_t i;

	if (!(tofind[0]))
		return ((char*)str);
	i = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], tofind, ft_strlen((char*)tofind)) == 0)
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
