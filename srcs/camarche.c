/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:12:17 by arusso            #+#    #+#             */
/*   Updated: 2018/06/09 17:44:17 by arusso           ###   ########.fr       */
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

int		key_hook(int key, t_global *g)
{
	(void)g;
	if (key == ESCAPE)
		exit (0);
	if ((key >= LEFT && key <= UP) || key == MINUS || key == PLUS || key == RESET)
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
	while (ex->i < ex->dx)
	{
		ex->p.x += ex->dirx;
		ex->sum += ex->dy;
		if (ex->sum >= ex->dx)
		{
			ex->sum -= ex->dx;
			ex->p.y += ex->diry;
		}
		if ((ex->p.x < WIDTH && ex->p.x >= 0) && (ex->p.y < HEIGHT && ex->p.y >= 0))
			mlx_pixel_put(g->mlx, g->win, ex->p.x + g->indx + ex->decalage, ex->p.y + g->indy, RED);
		ex->i++;
	}
}

void	draw_neg(t_global *g, t_local *ex)
{
	ex->sum = ex->dy / 2;
	ex->i = 0;
	while (ex->i < ex->dy)
	{
		if ((ex->p.x < WIDTH && ex->p.x >= 0) && (ex->p.y < HEIGHT && ex->p.y >= 0))
			mlx_pixel_put(g->mlx, g->win, ex->p.x + g->indx + ex->decalage, ex->p.y + g->indy, RED);
		ex->p.y += ex->diry;
		ex->sum += ex->dx;
		if (ex->sum >= ex->dy)
		{
			ex->sum -= ex->dy;
			ex->p.x += ex->dirx;
		}
		ex->i++;
	}
}

void	draw_one_line(t_global *g, t_local *ex)
{
	ex->p.x = ex->p0.x;
	ex->p.y = ex->p0.y;
	ex->dx = abs (ex->p1.x - ex->p0.x);
	ex->dy = abs (ex->p1.y - ex->p0.y);
	ex->dirx = (ex->p1.x - ex->p0.x > 0) ? 1 : -1;
	ex->diry = (ex->p1.y - ex->p0.y > 0) ? 1 : -1;
	if (ex->dx >= ex->dy)
		draw_pos(g, ex);
	else
		draw_neg(g, ex);
}

void	draw_lines(t_global *g, t_local *ex)
{
	if (ex->p0.x / g->pas != g->nb_cols - 1)
	{
		ex->p1.x = ex->p0.x + g->pas;
		ex->p1.y = ex->tmp_y;
		printf(" line : %d %d %d \n", ex->p1.y, ex->p1.x, g->pas);
		draw_one_line(g, ex);
	}
	if (ex->p0.y / g->pas != g->nb_lines - 1)
	{
		ex->p1.x = ex->p0.x + g->d;
		ex->p1.y = ex->tmp_y + g->pas;
		printf(" col : %d %d %d \n\n", ex->p1.y, ex->p1.x, g->pas);
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
		g->d = 15;
		g->indx = (WIDTH - g->w) / 2;
		g->indy = (HEIGHT - g->h) / 2;
		g->init++;
}

void	draw_map(t_global *g)
{
	t_local	l;

	if (g->init == 0)
		init_display(g);
	l.p0.x = 0;
	l.p0.y = 0;
	l.decalage = 0;
	l.tmp_y = l.p0.y;
	while (l.p0.x / g->pas < g->nb_cols - 1 || l.p0.y / g->pas < g->nb_lines - 1)
	{
		if (l.p0.x / g->pas > g->nb_cols - 1)
		{
			l.p0.x = 0;
			l.decalage += g->d;
			l.tmp_y += g->pas;
			l.p0.y = l.tmp_y;
		}
		l.p0.y = l.tmp_y - g->map[l.p0.y / g->pas][l.p0.x / g->pas];
		if (l.p0.y >= g->pas && l.p0.y <= g->pas * 2)
			printf("point : %d %d %d \n", l.p0.y, l.p0.x, g->pas);
		draw_lines(g, &l);
		l.p0.x += g->pas;
	}
	update_map(g);
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
