/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:23:41 by arusso            #+#    #+#             */
/*   Updated: 2017/11/17 15:42:02 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen((char*)s) - 1;
	while (s[start] && (s[start] == ' ' || s[start] == '\n' ||
				s[start] == '\t'))
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	while (s[end] && end > 0 && (s[end] == ' ' || s[end] == '\n' ||
				s[end] == '\t'))
		end--;
	return (ft_strsub(s, start, (end - start) + 1));
}
