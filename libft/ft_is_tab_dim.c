/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tab_dim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:40:38 by arusso            #+#    #+#             */
/*   Updated: 2017/12/16 15:45:01 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_tab_dim(char **tab, int x, int y)
{
	int i;
	int j;

	if (!tab || !x || !y)
		return (0);
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (j > x)
				return (0);
		}
	}
	if (i > y)
		return (0);
	return (1);
}
