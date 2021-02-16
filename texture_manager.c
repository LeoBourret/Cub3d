/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:38:08 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/16 15:58:12 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_p *p, int *texture, char *path, t_image *img)
{
	int y;
	int x;

	img->img_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
	path, &img->img_w, &img->img_h);
	if (!img->img_ptr)
		error_manager(0,p);
	img->img_data = (int *)mlx_get_data_addr(img->img_ptr,
	&img->bpp, &img->size_line, &img->endian);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			texture[img->img_w * y + x] = img->img_data[img->img_w * y + x];
	}
	mlx_destroy_image(p->mlx_ptr, img->img_ptr);
}

void	load_texture(t_p *p)
{
	t_image img;

	load_image(p, p->texture[0], p->info->no , &img);
	load_image(p, p->texture[1], p->info->so , &img);
	load_image(p, p->texture[2], p->info->s, &img);
	load_image(p, p->texture[3], "images/greenlight.xpm", &img);
	load_image(p, p->texture[4], p->info->ea , &img);
	load_image(p, p->texture[5], p->info->we , &img);
}

void	texture_engine(t_p *p, int line_height, int x)
{
	double wall_x;
	double step;
	double tex_pos;

	p->tex.tn = (int)(p->map[p->eng.map_x][p->eng.map_y]);
	if (p->eng.side == 0)
		wall_x = p->pos_y + p->eng.pwd * p->eng.ray_dir_y;
	else
		wall_x = p->pos_x + p->eng.pwd * p->eng.ray_dir_x;
	wall_x -= floor(wall_x);
	p->tex.tx = (int)(wall_x * (double)T_W);
	if (p->eng.side == 0 && p->eng.ray_dir_x > 0)
		p->tex.tx = T_W - p->tex.tx - 1;
	if (p->eng.side == 1 && p->eng.ray_dir_y < 0)
		p->tex.tx = T_W - p->tex.tx - 1;
	step = 1.0 * T_H / line_height;
	tex_pos = (p->eng.ds - p->res.height / 2 + line_height / 2) * step;
	texture_engine_bis(p, x, tex_pos, step);
	p->z_buf[x] = p->eng.pwd;
}

void	texture_engine_bis(t_p *p,
int x, double tex_pos, double step)
{
	int y;
	int tex_y;
	int color;
	double dx;
	double dy;

	dx = p->eng.map_x - p->pos_x;
	dy = p->eng.map_y - p->pos_y;
	y = -1;
	while (++y < p->eng.ds)
		p->buf[y][x] = p->rgb.c;
	y = p->eng.ds - 1;
	while (++y < p->eng.de)
	{
		tex_y = (int)tex_pos & (T_H - 1);
		tex_pos += step;
		if (p->eng.side == 0)
			if (dx > 0)
				color = p->texture[0][T_H * tex_y + p->tex.tx];
			else
				color = p->texture[1][T_H * 
				tex_y +
				 p->tex.tx];
		else
			if (dy > 0)
				color = p->texture[4][T_H * tex_y + p->tex.tx];
			else
				color = p->texture[5][T_H * tex_y + p->tex.tx];
		p->buf[y][x] = color;
	}
	y = p->eng.de - 1;
	while (++y < p->res.height)
		p->buf[y][x] = p->rgb.f;
}
