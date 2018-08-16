/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:12:17 by arusso            #+#    #+#             */
/*   Updated: 2018/08/16 15:44:06 by arusso           ###   ########.fr       */
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

void	update_color(int key, t_global *g)
{
	if (key == 87)
		g->color = WHITE;
	else if (key == 89 || key == 92)
		(key == 92) ? (g->color -= 0x080000) : (g->color += 0x080000);
	else if (key == 86 || key == 88)
		(key == 88) ? (g->color -= 0x000800) : (g->color += 0x000800);
	else if (key == 83 || key == 85)
		(key == 85) ? (g->color -= 0x000008) : (g->color += 0x000008);
	else if (key == 91 || key == 84)
		(key == 91) ? (g->color -= 0x080808) : (g->color += 0x080808);
}

void	zoom(int key, t_global *g)
{
	if (key == MULTIPLY && g->w * 2 <= WIDTH && g->h * 2 <= HEIGHT)
	{
		g->pas = g->pas * 2;
		g->dimx = g->dimx * 2;
		g->w *= 2;
		g->h *= 2;
	}
	if (key == DIVIDE && g->pas >= 1 && g->pas  >= 1 &&
		(-(g->dimx) * 0.5 >= 1 || g->dimx * 0.5 >= 1))
	{
		g->pas = g->pas / 2;
		g->dimx = g->dimx / 2;
		g->w /= 2;
		g->h /= 2;
	}
	if (key == DIVIDE || key == MULTIPLY)
	{
		g->indx = (WIDTH - g->w) / 2 - (g->pas/ 2 * (g->nb_lines - 1) / 2);
		g->indy = (HEIGHT - g->h) / 2;
	}
}

void	toupdate(int key, t_global *g)
{
	if (key == PLUS)
		g->dimy++;
	if (key == MINUS)
		g->dimy--;
	if (key == UP && g->indy - 5 >= 50)
		g->indy -= 5;
	if (key == DOWN && g->indy + 5 <= HEIGHT - 50)
		g->indy += 5;
	if (key == LEFT && g->indx - 5 >= 50)
		g->indx -= 5;
	if (key == RIGHT && g->indx + 5 <= WIDTH - 50)
		g->indx += 5;
	if (key == RESET)
		g->init = 0;
}

int		key_hook(int key, t_global *g)
{
	if (key == ESCAPE)
		exit (0);
	if ((key >= LEFT && key <= UP) || key == MINUS || key == PLUS 
			|| key == MULTIPLY || key == DIVIDE || key == RESET || (key >= 82 && key <= 92))
	{
		zoom(key, g);
		update_color(key, g);
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
		if ((ex->tpp.x < WIDTH && ex->tpp.x >= 0) && (ex->tpp.y < HEIGHT && ex->tpp.y >= 0))
			mlx_pixel_put(g->mlx, g->win, ex->tpp.x, ex->tpp.y, g->color);
		ex->tpp.x += ex->dirx;
		ex->sum += ex->dy;
		if (ex->sum >= ex->dx)
		{
			ex->sum -= ex->dx;
			ex->tpp.y += ex->diry;
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
		if ((ex->tpp.x < WIDTH && ex->tpp.x >= 0) && (ex->tpp.y < HEIGHT && ex->tpp.y >= 0))
			mlx_pixel_put(g->mlx, g->win, ex->tpp.x, ex->tpp.y, g->color);
		ex->tpp.y += ex->diry;
		ex->sum += ex->dx;
		if (ex->sum >= ex->dy)
		{
			ex->sum -= ex->dy;
			ex->tpp.x += ex->dirx;
		}
		ex->i++;
	}
}

void	draw_one_line(t_global *g, t_local *ex)
{
	ex->tpp.x = ex->p0.x;
	ex->tpp.y = ex->p0.y;
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
	ex->p0.x = g->indx + ex->p.x * g->pas + ex->decal_x;
	ex->p0.y = g->indy + ex->p.y * g->pas - g->map[ex->p.y][ex->p.x] * g->dimy;
	if (ex->p.x != g->nb_cols - 1)
	{
		ex->p1.x = g->indx + (ex->p.x + 1) * g->pas + ex->decal_x;
		ex->p1.y = g->indy + ex->p.y * g->pas - g->map[ex->p.y][ex->p.x + 1] * g->dimy;
		draw_one_line(g, ex);
	}
	if (ex->p.y != g->nb_lines - 1)
	{
		ex->p1.x = g->indx + ex->p.x * g->pas + ex->decal_x + g->dimx;
		ex->p1.y = g->indy + (ex->p.y + 1) * g->pas - g->map[ex->p.y + 1][ex->p.x] * g->dimy;
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
	g->dimx = g->pas / 2;
	g->dimy = 5;
	g->indx = (WIDTH - g->w) / 2 - (g->pas/ 2 * (g->nb_lines - 1) / 2);
	g->indy = (HEIGHT - g->h) / 2;
	g->init++;
	g->color = WHITE;
}

void	draw_map(t_global *g)
{
	t_local	l;

	if (g->init == 0)
		init_display(g);
	l.p.x = 0;
	l.p.y = 0;
	l.decal_x = 0;
	l.decal_y = 0;
	while (l.p.x < g->nb_cols - 1 || l.p.y < g->nb_lines - 1)
	{
		if (l.p.x > g->nb_cols - 1)
		{
			l.p.x = 0;
			l.decal_x += g->dimx;
			l.decal_y += g->pas;
			l.p.y++;
		}
		draw_lines(g, &l);
		l.p.x++;
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
