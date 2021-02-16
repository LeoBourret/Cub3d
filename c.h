/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 09:41:15 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/01 16:27:13 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define T_W 64
# define T_H 64
# define SPRITE_NUM 0

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct	s_image
{
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		endian;
	int		size_line;
	int		img_w;
	int		img_h;
}				t_image;

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		tex;
}				t_sprite;

typedef struct	s_sinit
{
	double	sx;
	double	sy;
	double	transx;
	double	transy;
	int		ssx;
	int		spw;
	int		sph;
	double	inv_det;
}				t_sinit;

typedef struct	s_keys
{
	int a;
	int s;
	int d;
	int w;
	int q;
	int e;
	int shift;
}				t_keys;

typedef struct	s_pair
{
	double	first;
	int		second;
}				t_pair;

typedef struct	s_engine
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	pwd;
	int		step_x;
	int		step_y;
	int		side;
	int		x;
	int		hit;
	int		line_height;
	int		ds;
	int		de;
}				t_engine;

typedef struct	s_texture
{
	int tx;
	int ty;
	int tn;
}				t_texture;

typedef struct	s_draw
{
	int sy;
	int ey;
	int sx;
	int ex;
}				t_draw;

typedef struct s_identifier_list
{
	char	*r;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	*f;
	char	*c;
	char	spawn_dir;
	int		spawn_coord[2];
}				t_identifier_list;

typedef struct	s_p
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	char **map_buffer;
	char **map;
	char		**map_data;
	double		pos_x;
	double		start_x;
	double		pos_y;
	double		start_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	t_keys		keys;
	int			**buf;
	double		*z_buf;
	int			*sprite_order;
	double		*sprite_dist;
	int			nb_texture;
	int			**texture;
	double		move_speed;
	double		boost_speed;
	double		rot_speed;
	t_engine	eng;
	t_texture	tex;
	t_sinit		si;
	t_draw		dw;
	int			v_mov_sc;
}				t_p;

void			engine_init(t_p *p, int x);
void			dda(t_p *p);
void			make_sprite(t_p *p, int i);
void			init_sprite(t_p *p);
void			step_calc (t_p *p);
void			texture_engine(t_p *p, int line_height, int x);
void			texture_engine_bis (t_p *p, int x, double tex_pos, double step);
void			make_sprite_init(t_p *p, int i);
void			straf_left(t_p *p, double ms);
void			straf_right(t_p *p, double ms);
void			make_sprite_init_bis (t_p *p, int v_mov_sc);
int				make_sprite_init_ter(t_p *p, int strp);
void			game(t_p *p);
void			game_bis(t_p *p);
void			hit(t_p *p);
void			load_texture(t_p *p);
void			init_bis (t_p *p);
void			load_image(t_p *p, int *texture, char *path, t_image *img);
int				loop(t_p *p);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
void			move_forward(t_p *p, double ms, double rs);
void			move_backward(t_p *p, double ms, double rs);
void			rot_left(t_p *p, double ms, double rs);
void			rot_right(t_p *p, double ms, double rs);
void			draw_line(t_p *p);
int				get_next_line(int fd, char **line);
char			**ft_realloc(char **str);
void			sort_sprites(int *order, double *dist, int amount);

#endif
