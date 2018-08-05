/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:38:25 by arusso            #+#    #+#             */
/*   Updated: 2017/12/16 14:39:51 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rec(const char **str, char c)
{
	int i;
	int count;

	if (!str || !c)
		return (0);
	i = -1;
	count = 0;
	while (str[++i])
		count = count + ft_strrec(str[i], c);
	return (count);
}
