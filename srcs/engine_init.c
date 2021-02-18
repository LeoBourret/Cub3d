/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:32:55 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/05 11:23:42 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	engine_init(t_p *p, int x)
{
	p->eng.camera_x = 2 * x / (double)p->res.width - 1;
	p->eng.ray_dir_x = p->dir_x +
	p->plane_x * p->eng.camera_x;
	p->eng.ray_dir_y = p->dir_y +
	p->plane_y * p->eng.camera_x;
	p->eng.map_x = (int)p->pos_x;
	p->eng.map_y = (int)p->pos_y;
	p->eng.delta_dist_x = fabs(1 / p->eng.ray_dir_x);
	p->eng.delta_dist_y = fabs(1 / p->eng.ray_dir_y);
}

void	dda(t_p *p)
{
	if (p->eng.side_dist_x < p->eng.side_dist_y)
	{
		p->eng.side_dist_x += p->eng.delta_dist_x;
		p->eng.map_x += p->eng.step_x;
		p->eng.side = 0;
	}
	else
	{
		p->eng.side_dist_y += p->eng.delta_dist_y;
		p->eng.map_y += p->eng.step_y;
		p->eng.side = 1;
	}
}

void	step_calc(t_p *p)
{
	if (p->eng.ray_dir_x < 0)
	{
		p->eng.step_x = -1;
		p->eng.side_dist_x =
		(p->pos_x - p->eng.map_x) * p->eng.delta_dist_x;
	}
	else
	{
		p->eng.step_x = 1;
		p->eng.side_dist_x =
		(p->eng.map_x + 1.0 - p->pos_x) * p->eng.delta_dist_x;
	}
	if (p->eng.ray_dir_y < 0)
	{
		p->eng.step_y = -1;
		p->eng.side_dist_y =
		(p->pos_y - p->eng.map_y) * p->eng.delta_dist_y;
	}
	else
	{
		p->eng.step_y = 1;
		p->eng.side_dist_y =
		(p->eng.map_y + 1.0 - p->pos_y) * p->eng.delta_dist_y;
	}
}
