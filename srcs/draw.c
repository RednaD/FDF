/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:49:56 by arusso            #+#    #+#             */
/*   Updated: 2018/08/16 15:57:37 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
