/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:12:17 by arusso            #+#    #+#             */
/*   Updated: 2018/08/18 18:33:40 by arusso           ###   ########.fr       */
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
	g->midx = WIDTH / 2;
	g->midy = HEIGHT / 2;
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->data = mlx_get_data_addr(g->img, &g->bits_per_pix, &g->line, &g->endian);
	free(name);
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
	mlx_key_hook(g.win, key_hook, &g);
	mlx_loop(g.mlx);
	return (0);
}
