/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:39:45 by arusso            #+#    #+#             */
/*   Updated: 2018/08/17 16:40:19 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
