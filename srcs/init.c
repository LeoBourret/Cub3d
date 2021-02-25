/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:51:38 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/19 10:28:19 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pos(t_p *p)
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

void	init_ter(t_p *p)
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
	p->boost = 2.5;
}

void	init_bis(t_p *p)
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

void	init(t_p *p)
{
	init_ter(p);
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

void	init_sprite(t_p *p)
{
	int i;

	init_sp(p);
	i = -1;
	while (++i < p->sp_num)
	{
		p->sprite_order[i] = i;
		p->sprite_dist[i] = ((p->pos_x - p->map_sp[i].x) *
		(p->pos_x - p->map_sp[i].x) + (p->pos_y - p->map_sp[i].y) *
		(p->pos_y - p->map_sp[i].y));
	}
	sort_sprites(p->sprite_order, p->sprite_dist, p->sp_num);
	i = -1;
	while (++i < p->sp_num)
		make_sprite(p, i);
}
