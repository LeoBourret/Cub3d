/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:16 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:27:57 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_p *p)
{
	int line_height;
	int x;

	x = 0;
	while (x < p->res.width)
	{
		engine_init(p, x);
		step_calc(p);
		hit(p);
		game_bis(p);
		line_height = (int)(p->res.height / p->eng.pwd);
		p->eng.ds = -line_height / 2 + p->res.height / 2;
		if (p->eng.ds < 0)
			p->eng.ds = 0;
		p->eng.de = line_height / 2 + p->res.height / 2;
		if (p->eng.de >= p->res.height)
			p->eng.de = p->res.height - 1;
		texture_engine(p, line_height, x);
		x++;
	}
	init_sprite(p);
}

void	game_bis(t_p *p)
{
	if (p->eng.side == 0)
		p->eng.pwd = (p->eng.map_x - p->pos_x +
		(1 - p->eng.step_x) / 2) / p->eng.ray_dir_x;
	else
		p->eng.pwd = (p->eng.map_y - p->pos_y +
		(1 - p->eng.step_y) / 2) / p->eng.ray_dir_y;
	if (p->eng.pwd == 0)
		p->eng.pwd = 0.1;
}

void	hit(t_p *p)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		dda(p);
		if (p->map[p->eng.map_x][p->eng.map_y] == '1')
			hit = 1;
	}
}
