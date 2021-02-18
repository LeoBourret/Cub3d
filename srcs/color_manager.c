/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:22:03 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/18 10:33:30 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_colors(char *s)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**sr;

	sr = ft_split(s, ',');
	r = ft_atoi(sr[0]);
	g = ft_atoi(sr[1]);
	b = ft_atoi(sr[2]);
	i = -1;
	while (sr[++i])
		free(sr[i]);
	free(sr);
	return ((r * 65536) + (g * 256) + b);
}

void		get_rgb(t_p *p)
{
	p->rgb.f = get_colors(p->info->f);
	p->rgb.c = get_colors(p->info->c);
}

void		draw_line(t_p *p)
{
	int y;
	int x;

	y = 0;
	while (y < p->res.height)
	{
		x = 0;
		while (x < p->res.width)
		{
			if (p->invert)
				p->img.img_data[y * p->res.width + x] = p->buf[(y / 2)][x];
			else
				p->img.img_data[y * p->res.width + x] = p->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(
		p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
}
