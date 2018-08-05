/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:16:46 by arusso            #+#    #+#             */
/*   Updated: 2017/11/13 15:23:37 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	tmp;
	int		i;

	i = 0;
	str = (char*)s;
	tmp = (char)c;
	while (n)
	{
		if (str[i] == tmp)
			return (str + i);
		i++;
		n--;
	}
	return (NULL);
}
