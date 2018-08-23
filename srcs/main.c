/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:12:17 by arusso            #+#    #+#             */
/*   Updated: 2018/08/23 18:19:34 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_global *g)
{
	char	*name;
	char	*tmp;

	g->init = 0;
	g->mlx = mlx_init();
	name = ft_strdup("FDF : ");
	tmp = name;
	name = ft_strjoin(name, g->title);
	free(tmp);
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, name);
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->data = mlx_get_data_addr(g->img, &g->bits_per_pix, &g->line, &g->endian);
	free(name);
}

void	init_display(t_global *g)
{
	printf("nb_cols =  %d\n", g->nb_cols);
	if (HEIGHT / g->nb_lines > WIDTH / g->nb_cols)
	{
		printf("Moo !\n");
		g->w = 3 * (WIDTH / 5);
		g->pas = g->w / (g->nb_cols == 1 ? 1 : (g->nb_cols - 1));
		g->h = (g->nb_lines - 1) * g->pas;
	}
	else
	{
		printf("Meuh !\n");
		g->h = 3 * (HEIGHT / 5);
		g->pas = g->h / (g->nb_lines == 1 ? 1 : (g->nb_lines - 1));
		g->w = (g->nb_cols - 1) * g->pas;
	}
	g->dimx = g->pas / 2;
	g->dimy = 5;
	g->indx = (WIDTH - g->w) / 2 - (g->pas / 2 * (g->nb_lines - 1) / 2);
	g->indy = (HEIGHT - g->h) / 2;
	g->init++;
	g->color = WHITE;
}

int		main(int ac, char **av)
{
	t_global	g;

	if (ac != 2)
		return (ft_error("Error : wrong number of arguments."));
	g.title = av[1];
	if (!(check_map(&g)))
		return (ft_error("Error : unvalid map."));
	if (!(init_map(&g)))
		return (ft_error("Error : map coudn't be loaded."));
	init(&g);
	draw_map(&g);
	mlx_key_hook(g.win, key_hook, &g);
	mlx_loop(g.mlx);
	return (0);
}
