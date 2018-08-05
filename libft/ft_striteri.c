/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:38:16 by arusso            #+#    #+#             */
/*   Updated: 2017/11/22 17:00:10 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int i;
	int length;

	if (!s || !f)
		return ;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}
