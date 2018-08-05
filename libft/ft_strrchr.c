/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:43:32 by arusso            #+#    #+#             */
/*   Updated: 2017/11/18 16:27:46 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = ft_strlen((char*)s);
	str = (char*)s;
	while (i >= 0 && str[i] != c)
	{
		if (&str[i] == s)
			return (NULL);
		i--;
	}
	return (&str[i]);
}
