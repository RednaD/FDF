/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:25:36 by arusso            #+#    #+#             */
/*   Updated: 2018/08/23 16:58:21 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 32
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
	int			sum;
	int			dirx;
	int			diry;
	int			x;
	int			y;
	int			decal_x;
	int			decal_y;
	t_point		p;
	t_point		p0;
	t_point		p1;
	t_point		tpp;
	int			tmp_y;
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
	int			indx;
	int			indy;
	int			w;
	int			h;
	int			nb_cols;
	int			nb_lines;
	int			color;
	int			endian;
	int			line;
	int			bits_per_pix;
}				t_global;

void			init(t_global *g);
void			update_color(int key, t_global *g);
void			zoom(int key, t_global *g);
void			toupdate(int key, t_global *g);
int				key_hook(int key, t_global *g);
void			update_map(t_global *g);
void			draw_pos(t_global *g, t_local *ex);
void			draw_neg(t_global *g, t_local *ex);
void			draw_one_line(t_global *g, t_local *ex);
void			draw_lines(t_global *g, t_local *ex);
void			init_display(t_global *g);
void			draw_map(t_global *g);
int				line_len(char *str);
char			*load_map(int fd);
int				check_lines(char **line);
int				check_map(t_global *g);
int				init_map(t_global *g);

#endif
