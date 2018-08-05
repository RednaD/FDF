/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:51:54 by arusso            #+#    #+#             */
/*   Updated: 2018/01/03 18:07:08 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccut(char **src, char c)
{
	size_t	i;
	char	*dest;
	char	*tmp;

	if (!(**src) || !c)
		return (NULL);
	i = 0;
	while ((*src)[i] != '\0' && (*src)[i] != c)
		i++;
	if (i == ft_strlen(*src))
	{
		dest = ft_strdup(*src);
		ft_strclr(*src);
	}
	else
	{
		dest = ft_strsub(*src, 0, i);
		tmp = (*src);
		*src = ft_strsub(*src, i + 1, ft_strlen(*src));
		free(tmp);
	}
	return (dest);
}
