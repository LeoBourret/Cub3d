/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:35:21 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/10 15:03:16 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sp(t_p *p)
{
	int x;
	int y;
	int z;

	x = -1;
	z = 0;
	while (++x < p->info->height)
	{
		y = -1;
		while (++y < p->info->width)
			if (p->map[x][y] == '2')
			{
				p->map_sp[z].y = y + 0.5;
				p->map_sp[z].x = x + 0.5;
				p->map_sp[z].tex = 2;
				z++;
			}
	}
	p->sp_num = z;
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

void	make_sprite(t_p *p, int i)
{
	int strp;
	int y;
	int d;
	int color;

	make_sprite_init(p, i);
	p->v_mov_sc = (int)(VMOVE / p->si.transy);
	make_sprite_init_bis(p, p->v_mov_sc);
	strp = p->dw.sx - 1;
	while (++strp < p->dw.ex)
	{
		if (make_sprite_init_ter(p, strp))
		{
			y = p->dw.sy - 1;
			while (++y < p->dw.ey)
			{
				d = (y - p->v_mov_sc) * 256 - p->res.height * 128 + p->si.sph * 128;
				p->tex.ty = ((d * T_H) / p->si.sph) / 256;
				color = p->texture[p->map_sp[p->sprite_order[i]].tex]
				[T_W * p->tex.ty + p->tex.tx];
				if ((color & 0x00FFFFFF) != 0)
					p->buf[y][strp] = color;
			}
		}
	}
}

void	make_sprite_init(t_p *p, int i)
{
	p->si.sx = p->map_sp[p->sprite_order[i]].x - p->pos_x;
	p->si.sy = p->map_sp[p->sprite_order[i]].y - p->pos_y;
	p->si.inv_det = 1.0 / (p->plane_x *
	p->dir_y - p->dir_x * p->plane_y);
	p->si.transx = p->si.inv_det * (p->dir_y *
	p->si.sx - p->dir_x * p->si.sy);
	p->si.transy = p->si.inv_det * (-p->plane_y *
	p->si.sx + p->plane_x * p->si.sy);
	p->si.ssx = (int)((p->res.width / 2) *
	(1 + p->si.transx / p->si.transy));
}

void	make_sprite_init_bis(t_p *p, int v_mov_sc)
{
	p->si.sph = (int)fabs((p->res.height / p->si.transy) / VDIV);
	p->dw.sy = -p->si.sph / 2 + p->res.height / 2 + v_mov_sc;
	if (p->dw.sy < 0)
		p->dw.sy = 0;
	p->dw.ey = p->si.sph / 2 + p->res.height / 2 + v_mov_sc;
	if (p->dw.ey >= p->res.height)
		p->dw.ey = p->res.height - 1;
	p->si.spw = (int)fabs((p->res.height / p->si.transy) / UDIV);
	p->dw.sx = -p->si.spw / 2 + p->si.ssx;
	if (p->dw.sx < 0)
		p->dw.sx = 0;
	p->dw.ex = p->si.spw / 2 + p->si.ssx;
	if (p->dw.ex >= p->res.width)
		p->dw.ex = p->res.width - 1;
}

int		make_sprite_init_ter(t_p *p, int strp)
{
	p->tex.tx = (int)((256 * (strp - (-p->si.spw / 2 + p->si.ssx)) *
	T_W / p->si.spw) / 256);
	return (p->si.transy > 0 && strp > 0 && strp < p->res.width &&
		p->si.transy < p->z_buf[strp]) ? 1 : 0;
}
