/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager_re.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 09:30:21 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/25 23:27:00 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_p *p, double ms)
{
	if (p->map[(int)(p->pos_x + p->dir_x * ms)][(int)p->pos_y] == '0'
	|| p->map[(int)(p->pos_x + p->dir_x * ms)][(int)p->pos_y] == '3')
		p->pos_x += p->dir_x * ms;
	if (p->map[(int)p->pos_x][(int)(p->pos_y + p->dir_y * ms)] == '0'
	|| p->map[(int)p->pos_x][(int)(p->pos_y + p->dir_y * ms)] == '3')
		p->pos_y += p->dir_y * ms;
}

void	move_backward(t_p *p, double ms)
{
	if (p->map[(int)(p->pos_x - p->dir_x * ms)][(int)p->pos_y] == '0'
	|| p->map[(int)(p->pos_x - p->dir_x * ms)][(int)p->pos_y] == '3')
		p->pos_x -= p->dir_x * ms;
	if (p->map[(int)p->pos_x][(int)(p->pos_y - p->dir_y * ms)] == '0'
	|| p->map[(int)p->pos_x][(int)(p->pos_y - p->dir_y * ms)] == '3')
		p->pos_y -= p->dir_y * ms;
}
