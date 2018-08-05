/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:13:29 by arusso            #+#    #+#             */
/*   Updated: 2018/06/09 17:09:15 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_nb(int n)
{
	int sign;
	int count;

	sign = 0;
	count = 1;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n > 10)
	{
		count++;
		n = n / 10;
	}
	return (count + sign);
}

int		*ft_splitoa(char *str, char c)
{
	int		*dest;
	int		count;
	int		i;
	int		j;

	count = ft_strlen(str) - ft_strrec(str, c);
	if (!(dest = (int*)malloc(sizeof(int) * count) + 1))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		dest[j] = ft_atoi(str + i);
		j++;
		while (str[i] != c && str[i])
			i++;
	}
	dest[j] = '\0';
	return (dest);
}

int		ft_test_map(char *str, t_global *g)
{
	char	**c_map;
	size_t	i;

	c_map = ft_strsplit(str, '\n');
	if (!(ft_test_line(c_map, g)))
		return (0);
	if (!(g->map = (int**)malloc(sizeof(int*) * ft_tablen(c_map) + 1)))
		return (0);
	i = 0;
	while (i != ft_tablen(c_map))
	{
		if (!(g->map[i] = ft_splitoa(c_map[i], ' ')))
			return (0);
		i++;
	}
	g->map[i] = NULL;
	return (1);
}

int		init_map(t_global *g)
{
	if (!(g->fd = open(g->title, O_RDONLY)) || g->fd == -1)
		return (0);
	if (!(ft_test_map(ft_load_map(g->fd), g)))
		return (0);
	return (1);
}
