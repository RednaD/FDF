/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:25:36 by arusso            #+#    #+#             */
/*   Updated: 2018/06/30 16:22:14 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>

# define WIDTH 1440
# define HEIGHT 900
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define K_RED 1
# define K_BLUE 3
# define K_GREEN 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MINUS 78
# define PLUS 69
# define MULTIPLY 67
# define DIVIDE 75
# define ESCAPE 53
# define RESET 15

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_local
{
	int			i;
	int			j;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int 		sum;
	int 		dirx;
	int 		diry;
	int			x;
	int			y;
	int			decal_x;
	int			decal_y;
	t_point		p;
	t_point		p0;
	t_point		p1;
	t_point		tpp;

	int		decalage;
	int tmp_y;
}				t_local;

typedef struct	s_global
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*title;
	char		*data;
	int			**map;
	int			fd;
	int			init;
	int			pas;
	int			dimx;
	int			dimy;
	int			midx;
	int			midy;
	int			indx;
	int			indy;
	int			w;
	int			h;
	int			nb_cols;
	int			nb_lines;
	int			color;
}				t_global;

void			draw_one_line(t_global *g, t_local *l);
void			draw_map(t_global *g);
void			init(t_global *g);
int				ft_test_line(char **str, t_global *g);
char			*ft_load_map(int fd);
int				*ft_splitoa(char *str, char c);
int				ft_test_map(char *str, t_global *g);
int				init_map(t_global *g);

#endif
