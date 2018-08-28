/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:13:30 by arusso            #+#    #+#             */
/*   Updated: 2018/08/28 22:59:50 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	if (!str || !str[i])
		return (0);
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}
