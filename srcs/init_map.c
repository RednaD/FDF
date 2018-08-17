/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:13:29 by arusso            #+#    #+#             */
/*   Updated: 2018/08/17 16:44:59 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_display(t_global *g)
{
	if (HEIGHT / g->nb_lines > WIDTH / g->nb_cols)
	{
		g->w = 3 * (WIDTH / 5);
		g->pas = g->w / (g->nb_cols - 1);
		g->h = (g->nb_lines - 1) * g->pas;
	}
	else
	{
		g->h = 3 * (HEIGHT / 5);
		g->pas = g->h / (g->nb_lines - 1);
		g->w = (g->nb_cols - 1) * g->pas;
	}
	g->dimx = g->pas / 2;
	g->dimy = 5;
	g->indx = (WIDTH - g->w) / 2 - (g->pas/ 2 * (g->nb_lines - 1) / 2);
	g->indy = (HEIGHT - g->h) / 2;
	g->init++;
	g->color = WHITE;
}

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
	free(c_map);
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
