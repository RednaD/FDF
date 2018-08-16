/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:05:29 by arusso            #+#    #+#             */
/*   Updated: 2018/08/15 16:24:43 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_linelen(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		while (!(ft_isdigit(str[i])))
			i++;
		if (ft_isdigit(str[i]))
			count++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (count);
}

int		ft_test_line(char **str, t_global *g)
{
	int 	len1;
	int		len2;
	int		i;

	len1 = ft_linelen(str[0]);
	i = 0;
	while (str[i])
	{
		len2 = ft_linelen(str[i]);
		if (len1 != len2)
			return (0);
		len1 = len2;
		i++;
	}
	g->nb_cols = len1;
	g->nb_lines = i;
	return (1);
}

char	*ft_load_map(int fd)
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
			if (str)
				free (str);
			if (line)
				free (line);
			return (NULL);
		}
		tmp = str;
		str = ft_strjoin(str, line);
		free(line);
		str = ft_strjoin(str, "\n");
		free(tmp);
	}
	return (str);
}
