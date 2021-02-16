/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager_re.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 09:30:21 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/05 11:22:43 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_p *p, double ms)
{
	if (p->map[(int)(p->pos_x + p->dir_x * ms)]
	[(int)p->pos_y] != '1')
		p->pos_x += p->dir_x * ms;
	if (p->map[(int)p->pos_x]
	[(int)(p->pos_y + p->dir_y * ms)] != '1')
		p->pos_y += p->dir_y * ms;
}

void	move_backward(t_p *p, double ms)
{
	if (p->map[(int)(p->pos_x - p->dir_x * ms)]
	[(int)p->pos_y] != '1')
		p->pos_x -= p->dir_x * ms;
	if (p->map[(int)p->pos_x]
	[(int)(p->pos_y - p->dir_y * ms)] != '1')
		p->pos_y -= p->dir_y * ms;
}