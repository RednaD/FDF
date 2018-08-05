/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:29:08 by arusso            #+#    #+#             */
/*   Updated: 2017/11/29 23:46:41 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_test(int *i, int *negatif, const char *str)
{
	while ((str[*i] == '\n') || (str[*i] == '\t') || (str[*i] == '\v') ||
				(str[*i] == ' ') || (str[*i] == '\f') || (str[*i] == '\r'))
		*i = *i + 1;
	if (str[*i] == '-')
	{
		*negatif = 1;
	}
	if (str[*i] == '+' || str[*i] == '-')
		*i = *i + 1;
}

int			ft_atoi(const char *str)
{
	int nb;
	int negatif;
	int	i;

	i = 0;
	nb = 0;
	negatif = 0;
	if (!*str)
		return (0);
	ft_test(&i, &negatif, str);
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (negatif == 1)
		nb = -nb;
	return (nb);
}
