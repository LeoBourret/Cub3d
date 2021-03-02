/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:21:13 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/19 10:34:36 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_all(t_p *p)
{
	free_prog(p);
	exit(0);
}

void	free_rest_rest_rest(t_p *par)
{
	int i;

	i = -1;
	if (par->buf)
	{
		while (++i < par->res.height)
			free(par->buf[i]);
		free(par->buf);
	}
	i = -1;
	if (par->texture)
	{
		while (++i < par->nb_texture)
			free(par->texture[i]);
		free(par->texture);
	}
	if (par->win_ptr)
		free(par->win_ptr);
	if (par->mlx_ptr)
		free(par->mlx_ptr);
	if (par)
		free(par);
}

void	free_rest_rest(t_p *par)
{
	if (par->z_buf)
		free(par->z_buf);
	if (par->map_sp)
		free(par->map_sp);
	if (par->sprite_dist)
		free(par->sprite_dist);
	if (par->sprite_order)
		free(par->sprite_order);
	if (par->save)
		free(par->save);
	free_rest_rest_rest(par);
}

void	free_rest(t_p *par)
{
	free(par->info->r);
	free(par->info->no);
	free(par->info->so);
	free(par->info->we);
	free(par->info->ea);
	free(par->info->s);
	free(par->info->s2);
	free(par->info->f);
	free(par->info->c);
	free(par->info);
	if (par->win_ptr)
		free(par->win_ptr);
	free_rest_rest(par);
}

void	free_prog(t_p *par)
{
	int i;

	i = -1;
	if (par->map_buffer)
	{
		while (++i < par->buff_size)
			free(par->map_buffer[i]);
		free(par->map_buffer);
	}
	i = -1;
	if (par->map)
	{
		while (par->map[++i] && par->map[i][0])
			free(par->map[i]);
		free(par->map);
	}
	if (par->mlx_ptr && par->img.img_ptr)
		mlx_destroy_image(par->mlx_ptr, par->img.img_ptr);
	if (par->mlx_ptr && par->img.img_ptr)
		mlx_destroy_window(par->mlx_ptr, par->win_ptr);
	free_rest(par);
}
