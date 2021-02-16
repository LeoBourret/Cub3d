/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:30:10 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/10 14:40:30 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_left(t_p *p, double rs)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rs) - p->dir_y * sin(rs);
	p->dir_y = old_dir_x * sin(rs) + p->dir_y * cos(rs);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rs) - p->plane_y * sin(rs);
	p->plane_y = old_plane_x * sin(rs) + p->plane_y * cos(rs);
}

void	rot_right(t_p *p, double rs)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-rs) - p->dir_y * sin(-rs);
	p->dir_y = old_dir_x * sin(-rs) + p->dir_y * cos(-rs);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-rs) - p->plane_y * sin(-rs);
	p->plane_y = old_plane_x * sin(-rs) + p->plane_y * cos(-rs);
}

void	straf_left(t_p *p, double ms)
{
	if (p->map[(int)p->pos_x]
	[(int)(p->pos_y - p->plane_y * ms)] != '1')
		p->pos_y -= p->plane_y * ms;
	if (p->map[(int)(p->pos_x - p->plane_x * ms)]
	[(int)p->pos_y] != '1')
		p->pos_x -= p->plane_x * ms;
}

void	straf_right(t_p *p, double ms)
{
	if (p->map[(int)p->pos_x]
	[(int)(p->pos_y + p->plane_y * ms)] != '1')
		p->pos_y += p->plane_y * ms;
	if (p->map
	[(int)(p->pos_x
	 + p->plane_x * ms)]
	[(int)p->pos_y] != '1')
		p->pos_x += p->plane_x * ms;
}
