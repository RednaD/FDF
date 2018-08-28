/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:13:29 by arusso            #+#    #+#             */
/*   Updated: 2018/08/28 22:41:59 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_lines(char **line)
{
	static int	count;
	int			len;
	int			i;

	if (!count)
		count = 0;
	len = ft_count_word(*line, ' ');
	if (count == 0)
		count = len;
	if ((count != len) || (len == 0))
		return (0);
	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] != ' ' && (*line)[i] != '\t')
			if (((*line)[i] < '0' || (*line)[i] > '9') && (*line)[i] != '-')
				return (0);
	}
	return (1);
}

int		check_map(t_global *g)
{
	int		ret;
	char	*line;

	if (!(g->fd = open(g->title, O_RDONLY)))
		return (ft_error("Error : coudn't open map."));
	line = NULL;
	g->nb_lines = 0;
	while ((ret = get_next_line(g->fd, &line)) > 0)
	{
		if ((check_lines(&line)) != 1)
			return (0);
		g->nb_lines++;
		ft_strdel(&line);
	}
	if ((close(g->fd)) == -1 || g->nb_lines == 0)
		return (0);
	if ((g->fd = open(g->title, O_RDONLY)) == -1)
		return (0);
	return (1);
}

char	*load_map(int fd)
{
	char	*line;
	char	*str;
	char	*tmp;
	int		ret;

	str = ft_strnew(0);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			free(str);
			free(line);
			return (NULL);
		}
		tmp = str;
		str = ft_strjoin(str, line);
		free(line);
		str = ft_strcat(str, "\n");
		free(tmp);
	}
	close(fd);
	return (str);
}

int		init_map(t_global *g)
{
	char	**c_map;
	size_t	i;
	char	*str;

	str = load_map(g->fd);
	c_map = ft_strsplit(str, '\n');
	g->nb_cols = ft_count_word((const char*)c_map[0], ' ');
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
	i = -1;
	while (c_map[++i])
		free(c_map[i]);
	free(c_map);
	free(str);
	return (1);
}
