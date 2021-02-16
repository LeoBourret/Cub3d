/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:21:13 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/04 17:00:04 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_rest(t_p *par)
{
	if (par->info->r)
		free(par->info->r);
	if (par->info->no)
		free(par->info->no);
	if (par->info->so)
		free(par->info->so);
	if (par->info->we)
		free(par->info->we);
	if (par->info->ea)
		free(par->info->ea);
	if (par->info->s)
		free(par->info->s);
	if (par->info->f)
		free(par->info->f);
	if (par->info->c)
		free(par->info->c);
	if (par->info)
		free(par->info);
	free(par);
	while (1)
		;
}

void	free_prog(t_p *par)
{
	int i;

	i = -1;
	if (par->map_buffer)
	{
		while (is_identifier(par->map_buffer[++i]) || par->map_buffer[i][0] == '\0')
				free(par->map_buffer[i]);
		free(par->map_buffer);
	}
	i = -1;
	if (par->map)
	{
		while (par->map[++i])
			free(par->map[i]);
		free(par->map);
	}
	free_rest(par);
}
