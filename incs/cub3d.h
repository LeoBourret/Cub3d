/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 09:41:15 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/19 10:27:33 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define T_W 64
# define T_H 64
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct	s_save
{
	int				save;
	int				size;
	char			*img;
	unsigned char	header[14];
	unsigned char	data[40];
	unsigned char	padding[3];
	int				rgb;
}				t_save;

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
	int		sp_num;
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

typedef struct	s_identifier_list
{
	char	*r;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	*s2;
	char	*f;
	char	*c;
	int		width;
	int		height;
	int		sp_nb;
	char	spawn_dir;
	int		spawn_coord[2];
}				t_identifier_list;

typedef struct	s_resol
{
	int width;
	int height;
}				t_resol;

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
	int		c;
	int		f;
}				t_rgb;

typedef struct	s_p
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_image				img;
	int					screen_s_x;
	int					screen_s_y;
	char				**map_buffer;
	char				**map;
	t_sprite			*map_sp;
	t_resol				res;
	int					sp_num;
	char				**map_data;
	double				pos_x;
	double				pos_y;
	double				start_x;
	double				start_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	t_keys				keys;
	int					**buf;
	double				*z_buf;
	int					*sprite_order;
	double				*sprite_dist;
	int					nb_texture;
	int					**texture;
	double				move_speed;
	double				boost;
	double				rot_speed;
	t_engine			eng;
	t_texture			tex;
	t_sinit				si;
	t_draw				dw;
	t_save				*save;
	int					v_mov_sc;
	t_identifier_list	*info;
	t_rgb				rgb;
	int					invert;
	int					buff_size;
}				t_p;

void			exit_all (t_p *p);
void			get_rgb(t_p *p);
void			refill_map(t_p *p);
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
void			init_sp(t_p *p);
void			init(t_p *p);
void			game_bis(t_p *p);
void			hit(t_p *p);
void			load_texture(t_p *p);
void			init_pos(t_p *p);
void			init_bis (t_p *p);
void			load_image(t_p *p, int *texture, char *path, t_image *img);
int				loop(t_p *p);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
void			move_forward(t_p *p, double ms);
void			move_backward(t_p *p, double ms);
void			rot_left(t_p *p, double rs);
void			rot_right(t_p *p, double rs);
void			draw_line(t_p *p);
int				deal_key(void *param);
int				get_next_line(int fd, char **line);
char			*get_data(char *s, t_p *p);
void			copy_buffer_into_map(char **map, t_p *par);
void			free_prog(t_p *par);
int				manage_map(int fd, t_p *par, int i, int j);
int				error_manager(int error, t_p *par);
int				is_map_elem(char c);
int				is_map_elem(char c);
int				is_identifier(char *s);
int				is_spawn(char c);
int				skip_space(int i, char *s);
int				skip_nb(int i, char *s);
int				check_rgb(char *s);
int				check_file(char *file);
int				check_map_error(char **map, int i, int j, int inside);
int				check_missing_info(t_identifier_list *list);
void			check_which_info(char *s, t_p *par, int index);
int				map_size(char **map);
void			copy_buffer_into_map(char **map, t_p *par);
void			sort_sprites(int *order, double *dist, int amount);
void			manage_args(int ac, char **av, t_p *par);
void			manage_save(t_p *p);
void			set_info_to_null(t_p *p);
#endif
