/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:39:27 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/19 10:28:20 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			deal_key(void *param)
{
	t_p *p;

	p = (t_p *)param;
	if (p->keys.shift == 1)
		p->boost = 2;
	else if (p->keys.shift == 0)
		p->boost = 1;
	if (p->keys.q == 1)
		rot_left(p, p->move_speed * p->boost);
	if (p->keys.e == 1)
		rot_right(p, p->move_speed * p->boost);
	if (p->keys.a == 1)
		straf_left(p, p->move_speed * p->boost);
	if (p->keys.s == 1)
		move_backward(p, p->move_speed * p->boost);
	if (p->keys.d == 1)
		straf_right(p, p->move_speed * p->boost);
	if (p->keys.w == 1)
		move_forward(p, p->move_speed * p->boost);
	return (0);
}

int			key_press(int key, void *param)
{
	t_p			*p;

	p = (t_p *)param;
	if (key == 65361)
		p->keys.q = 1;
	if (key == 65363)
		p->keys.e = 1;
	if (key == 113 || key == 97)
		p->keys.a = 1;
	if (key == 115)
		p->keys.s = 1;
	if (key == 100)
		p->keys.d = 1;
	if (key == 122 || key == 119)
		p->keys.w = 1;
	if (key == 65307)
		exit_all(p);
	if (key == 65505)
		p->keys.shift = 1;
	if (key == 105)
		p->invert = p->invert == 0 ? 1 : 0;
	return (0);
}

int			key_release(int key, void *param)
{
	t_p			*p;

	p = (t_p *)param;
	if (key == 65361)
		p->keys.q = 0;
	if (key == 65363)
		p->keys.e = 0;
	if (key == 113 || key == 97)
		p->keys.a = 0;
	if (key == 115)
		p->keys.s = 0;
	if (key == 100)
		p->keys.d = 0;
	if (key == 122 || key == 119)
		p->keys.w = 0;
	if (key == 65505)
		p->keys.shift = 0;
	return (0);
}
