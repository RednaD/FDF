/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:12:17 by arusso            #+#    #+#             */
/*   Updated: 2018/05/28 14:54:46 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_global *g)
{
	char	*name;

	g->init = 0;
	g->mlx = mlx_init();
	name = ft_strdup("FDF : ");
	name = ft_strjoin(name, g->title);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, name);
	g->midx = WIDTH / 2;
	g->midy = HEIGHT / 2;
	free(name);
}

void	toupdate(int key, t_global *g)
{
	if (key == LEFT)
		g->midx--;
	if (key == RIGHT)
		g->midx++;
	if (key == UP)
		g->midy--;
	if (key == DOWN)
		g->midy++;
	if (key == RESET)
		g->init = 0;
	if (key == PLUS && g->pas * 2 <= 500 && g->pas * 2 <= 500)
	{
		g->pas = g->pas * 2;
		g->d = g->d * 2;
	}
	if (key == MINUS && g->pas * 0.5 >= 1 && g->pas * 0.5 >= 1 &&
		(-(g->d) * 0.5 >= 1 || g->d * 0.5 >= 1))
	{
		g->pas = g->pas / 2;
		g->d = g->d / 2;
	}
}

int	key_hook(int key, t_global *g)
{
	(void)g;
	if (key == ESCAPE)
		exit (0);
	if ((key >= LEFT && key <= UP) || key == MINUS || key == PLUS)
	{
		toupdate(key, g);
		mlx_clear_window(g->mlx, g->win);
		draw_map(g);
	}
	return (0);
}

void	update_map(t_global *g)
{
	mlx_key_hook(g->win, key_hook, g);
	mlx_loop(g->mlx);
}

void	draw_pos(t_global *g, t_local *ex)
{
	ex->sum = ex->dx / 2;
	ex->i = 0;
	while (ex->i <= ex->dx)
	{
		ex->x += ex->dirx;
		ex->sum += ex->dy;
		if (ex->sum >= ex->dx)
		{
			ex->sum -= ex->dx;
			ex->y += ex->diry;
		}
			printf("put :%d %d\n", ex->x, ex->y);
		if ((ex->x < WIDTH && ex->x > 0) && (ex->y = HEIGHT && ex->y > 0))
		{
			mlx_pixel_put(g->mlx, g->win, ex->x, ex->y, RED);
			//mlx_pixel_put(g->mlx, g->win, ex->x + g->indx, ex->y - g->indy, RED);
		}
		ex->i++;
	}
}

void	draw_neg(t_global *g, t_local *ex)
{
	ex->sum = ex->dy / 2;
	ex->i = 0;
	while (ex->i <= ex->dy)
	{
		ex->y += ex->diry;
		ex->sum += ex->dx;
		if (ex->sum >= ex->dy)
		{
			ex->sum -= ex->dy;
			ex->x += ex->dirx;
		}
			printf("put :%d %d\n", ex->x, ex->y);
		if ((ex->x < WIDTH && ex->x > 0) && (ex->y = HEIGHT && ex->y > 0))
		{
		/*	ft_putstr("x = ");
			ft_putnbr(ex->x);
			ft_putstr(", y = ");
			ft_putnbr(ex->y);
			ft_putendl("");
		*/	
			mlx_pixel_put(g->mlx, g->win, ex->x, ex->y, RED);
			//mlx_pixel_put(g->mlx, g->win, ex->x + g->indx, ex->y - g->indy, RED);
		}
		ex->i++;
	}
}

void	draw_one_line(t_global *g, t_local *ex)
{
			/*ft_putstr("x0 = ");
			ft_putnbr(ex->x0);
			ft_putstr(", x1 = ");
			ft_putnbr(ex->x1);
			ft_putendl("");
			ft_putstr(", y0 = ");
			ft_putnbr(ex->y0);
			ft_putstr("y1 = ");
			ft_putnbr(ex->y1);*/
	ex->x = ex->x0;
	ex->y = ex->y0;
			printf("tu te fou de moi? :%d %d\n", ex->x, ex->y);
	ex->dx = abs (ex->x1 - ex->x0);
	ex->dy = abs (ex->y1 - ex->y0);
	ex->dirx = (ex->x1 - ex->x0 > 0) ? 1 : -1;
	ex->diry = (ex->y1 - ex->y0 > 0) ? 1 : -1;
	if (ex->dx < ex->dy)
		draw_pos(g, ex);
	else
		draw_neg(g, ex);
}

void	draw_lines(t_global *g, t_local *ex)
{
/*	ft_putendl("");
	ft_putendl("y0 = ");
	ft_putnbr(ex->y0);
	ft_putendl("");
*/	if (ex->x0 / g->pas != g->nb_cols)
	{
//		ft_putendl("Ici !");
		ex->x1 = ex->x0 + g->pas;
		ex->y1 = ex->y0;
		printf(" enter : %d %d %d \n", ex->y0, ex->x0, g->pas);
		draw_one_line(g, ex);
	}
	if (ex->y0 / g->pas != g->nb_lines)
	{
//		ft_putendl("Meh !");
		ex->x1 = ex->x0;
		ex->y1 = ex->y0 + g->pas;
		printf(" exit : %d %d %d \n\n", ex->y0, ex->x0, g->pas);
		draw_one_line(g, ex);
	}
}

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
		g->d = 0;
		g->indx = (WIDTH - g->w) / 2;
		g->indy = (HEIGHT - g->h) / 2;
		g->init++;
}

void	draw_map(t_global *g)
{
	t_local	*l;

	if (g->init == 0)
		init_display(g);
	l->x0 = 0;
	l->y0 = 0;
	ft_putnbr(g->w);
	ft_putstr(" / ");
	ft_putnbr(g->nb_cols - 1);
	ft_putstr(" = ");
	ft_putnbr(g->pas);
	ft_putendl("");
	ft_putendl("");
	while (l->x0 / g->pas < g->nb_cols - 1 || l->y0 / g->pas < g->nb_lines - 1)
	{
/*	ft_putnbr(g->pas);
	ft_putendl("");
	ft_putendl("y0 = ");
	ft_putnbr(l->y0);
	ft_putendl("");
*/		if (l->x0 / g->pas > g->nb_cols - 1)
		{
			l->x0 = 0;
			l->y0 = l->y0 + g->pas;
		}
		printf("in : %d %d %d \n", l->y0, l->x0, g->pas);
		draw_lines(g, l);
		l->x0 = l->x0 + g->pas;
	}
	update_map(g);
}

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
	while (str[++i])
	{
		len2 = ft_linelen(str[i]);
		if (len1 != len2)
			return (0);
		len1 = len2;
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
		str = ft_strjoin(str, "\n");
		free(tmp);
	}
	return (str);
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
	int		i;

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
	char	str;

	if (!(g->fd = open(g->title, O_RDONLY)) || g->fd == -1)
		return (0);
	if (!(ft_test_map(ft_load_map(g->fd), g)))
		return (0);
	return (1);	
}

int		main(int ac, char **av)
{
	t_global	g;

	if (ac != 2)
		return (ft_error("Error : wrong number of arguments."));
	g.title = av[1];
	if (!(g.fd = open(g.title, O_RDONLY)))
		return (ft_error("Coudn't read file."));
	if (!(init_map(&g)))
		return (ft_error("Error : map coudn't be loaded."));
	init(&g);
	draw_map(&g);
	return (0);
}
