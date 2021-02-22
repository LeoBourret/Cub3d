/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:21:13 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:34:36 by jurichar         ###   ########.fr       */
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
	if (par->save)
		free(par->save);
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
	free_rest_rest(par);
}

void	free_prog(t_p *par)
{
	int i;

	i = -1;
	if (par->map_buffer)
	{
		while (par->map_buffer[++i]
		&& (is_identifier(par->map_buffer[i]) || par->map_buffer[i][0] == '\0'))
			free(par->map_buffer[i]);
		free(par->map_buffer);
	}
	i = -1;
	if (par->map)
	{
		while (++i < par->info->height)
			free(par->map[i]);
		free(par->map);
	}
	free_rest(par);
}
