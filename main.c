/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:26:17 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/16 15:49:40 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			deal_key(void *param)
{
	t_p *p;

	p = (t_p *)param;
	if (p->keys.shift == 1)
		p->boost_speed = 2;
	else if (p->keys.shift == 0)
		p->boost_speed = 1;
	if (p->keys.q == 1)
		rot_left(p, p->move_speed *
		p->boost_speed);
	if (p->keys.e == 1)
		rot_right(p, p->move_speed *
		p->boost_speed);
	if (p->keys.a == 1)
		straf_left(p, p->move_speed *
		p->boost_speed);
	if (p->keys.s == 1)
		move_backward(p, p->move_speed *
		p->boost_speed);
	if (p->keys.d == 1)
		straf_right(p, p->move_speed *
		p->boost_speed);
	if (p->keys.w == 1)
		move_forward(p, p->move_speed *
		p->boost_speed);
	return (0);
}

int			loop(t_p *p)
{
	game(p);
	draw_line(p);
	if (p->save->save == 1)
		manage_save(p);
	deal_key(p);
	return (0);
}

void set_res(t_p *p)
{
	char *res;
	char *s;
	int i;

	res = p->info->r;
	i = -1;
	s = malloc(sizeof(char) * ft_strlen(res));
	while (res[++i] != ' ')
	{
			s[i] = res[i];
	}
	s[i] = 0;
	p->res.width = (ft_atoi(s) >= p->screen_s_x) ? p->screen_s_x : ft_atoi(s);
	p->res.height = (ft_atoi(&res[i]) >= p->screen_s_y) ? p->screen_s_y : ft_atoi(&res[i]);
	free(s);
}

t_p*			mlx_first(void)
{
	t_p *p = (t_p*)malloc(sizeof(t_p));
	p->mlx_ptr = mlx_init();
	return (p);
}
void			init_pos(t_p *p)
{
	if (p->info->spawn_dir == 'N')
	{
		p->dir_x = -1;
		p->plane_y = 0.66;
	}
	if (p->info->spawn_dir == 'S')
	{
		p->dir_x = 1;
		p->plane_y = -0.66;
	}
	if (p->info->spawn_dir == 'E')
	{
		p->dir_y = 1;
		p->plane_x = 0.66;
	}
	if (p->info->spawn_dir == 'W')
	{
		p->dir_y = -1;
		p->plane_x = -0.66;
	}
}

void			init(t_p *p)
{
	p->keys.a = 0;
	p->keys.s = 0;
	p->keys.d = 0;
	p->keys.w = 0;
	p->keys.shift = 0;
	p->keys.q = 0;	
	p->keys.e = 0;
	p->dw.ex = 0;
	p->dw.ey = 0;
	p->dw.sx = 0;
	p->dw.sy = 0;
	p->si.sy = 0;
	p->si.sy = 0;
	p->invert = 0;
	p->pos_x = 0;
	p->pos_y = 0;
	p->eng.de = 0;
	p->eng.ds = 0;
	p->move_speed = 0.05;
	p->rot_speed = 0.05;
	p->boost_speed = 2.5;
	p->win_ptr = mlx_new_window(p->mlx_ptr, p->res.width, p->res.height, "kub");
	p->img.img_ptr = mlx_new_image(p->mlx_ptr, p->res.width, p->res.height);
	p->img.img_data = (int *)mlx_get_data_addr(p->img.img_ptr,
	&p->img.bpp, &p->img.endian, &p->img.size_line);
	init_pos(p);
	p->nb_texture = 11;
	p->buf = (int **)malloc(sizeof(int *) * p->res.height);
	p->z_buf = (double *)malloc(sizeof(double) * p->res.width);
	p->map_sp = malloc(sizeof(t_sprite) * p->info->sp_nb);
	p->sprite_dist = (double *)malloc(sizeof(double) * p->info->sp_nb);
	p->sprite_order = (int *)malloc(sizeof(int) * p->info->sp_nb);
	init_bis(p);
}

void		init_bis(t_p *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->res.height)
		p->buf[i] = (int *)malloc(sizeof(int) * p->res.width);
	i = -1;
	while (++i < p->res.height)
	{
		j = -1;
		while (++j < p->res.width)
			p->buf[i][j] = 0;
	}
	p->texture = (int **)malloc(sizeof(int *) * p->nb_texture);
	i = -1;
	while (++i < p->nb_texture)
		p->texture[i] =
		(int *)malloc(sizeof(int) * (T_H * T_W));
	i = -1;
	while (++i < p->nb_texture)
	{
		j = -1;
		while (++j < T_H * T_W)
			p->texture[i][j] = 0;
	}
}

int ext ()
{
	exit(0);
	return 0;
}

int			main(int ac, char **av)
{
	t_p *p;
	int fd;

	p = mlx_first();
	set_info_to_null(p);
	manage_args(ac, av, p);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		exit_all(p);
	manage_map(fd, p, -1);
	close(fd);
	mlx_get_screen_size(p->mlx_ptr,&p->screen_s_x,&p->screen_s_y);
	set_res(p);
	init(p);
	load_texture(p);
	get_rgb(p);
	p->pos_x = p->info->spawn_coord[1] + 0.5;
	p->pos_y = p->info->spawn_coord[0] + 0.5;
	mlx_hook(p->win_ptr, 2, (1L << 0), key_press, (void *)p);
	mlx_hook(p->win_ptr, 3, (1L << 1), key_release, (void *)p);
	mlx_loop_hook(p->mlx_ptr, loop, (void *)p);
	mlx_hook(p->win_ptr, 33, 1L << 5, ext, (void *)p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
