/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:45:12 by arusso            #+#    #+#             */
/*   Updated: 2018/08/05 14:20:15 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			file;
	static char	*memory;

	if (fd < 0 || fd > 10000 || line == NULL)
		return (-1);
	if (!memory)
		memory = ft_strnew(0);
	*line = NULL;
	file = 1;
	while (!(ft_strrec(memory, '\n')) && file > 0)
	{
		if ((file = read(fd, buffer, BUFF_SIZE)) == -1)
			return (file);
		buffer[file] = '\0';
		tmp = memory;
		memory = ft_strjoin(memory, buffer);
		free(tmp);
	}
	if (!(*line = ft_strccut(&memory, '\n')))
		return (0);
	return ((file + ft_strlen(*line) != 0) ? 1 : 0);
}
