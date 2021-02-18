/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:49:10 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/16 15:44:07 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	set_spawn_info(char **map, int i, int j, t_p *par)
{
	par->info->spawn_dir = (int)map[i][j];
	par->info->spawn_coord[0] = j;
	par->info->spawn_coord[1] = i;
}

int		set_inside(char **map, int i, int j, int inside)
{
	if (inside == 0 && (map[i][j] == '0' || is_spawn(map[i][j])
	|| map[i][j] == '2'))
		inside = 1;
	else if (inside == 1 && map[i][j] == '1')
		inside = 0;
	return (inside);
}

int		check_line(char **map, int i, t_p *par)
{
	int j;
	int inside;

	inside = 0;
	j = -1;
	while (map[i][++j])
	{
		inside = set_inside(map, i, j, inside);
		if (!is_map_elem(map[i][j]))
			return (-10);
		if (!check_map_error(map, i, j, inside))
			return (-11);
		if ((is_spawn(map[i][j])) && par->info->spawn_dir == 0)
			set_spawn_info(map, i, j, par);
		else if (is_spawn(map[i][j]) && par->info->spawn_dir > 0)
			return (-12);
		if (map[i][j] == '2' || map[i][j] == '3')
			par->info->sp_nb++;
	}
	return (1);
}

int		get_map(char **map, t_p *par)
{
	int i;
	int ret;

	ret = 1;
	par->info->spawn_dir = 0;
	par->info->sp_nb = 0;
	if (!map[0])
		return (-9);
	if (!(par->map = malloc(sizeof(char *) * (map_size(map) + 1))))
		return (0);
	i = -1;
	while (map[++i])
	{
		ret = check_line(map, i, par);
		if (ret < 1)
			return (ret);
		par->map[i] = map[i];
	}
	par->map[i] = NULL;
	if (par->info->spawn_dir == 0)
		return (-13);
	refill_map(par);
	return (1);
}

int		manage_map(int fd, t_p *par, int i)
{
	par->map_buffer = ft_realloc_double(par->map_buffer);
	while (get_next_line(fd, &par->map_buffer[++i]) > 0)
		par->map_buffer = ft_realloc_double(par->map_buffer);
	if (get_next_line(fd, &par->map_buffer[i]) < 0)
		return (error_manager(19, par));
	else
		par->map_buffer[i] = NULL;
	i = -1;
	while (par->map_buffer[++i] != NULL
	&& (is_identifier(par->map_buffer[i]) || par->map_buffer[i][0] == '\0'))
		if (is_identifier(par->map_buffer[i]))
			check_which_info(par->map_buffer[i], par);
	if (par->map_buffer[i] != NULL && (!is_identifier(par->map_buffer[i])
	&& par->map_buffer[i][0] != '\0') && !is_map_elem(par->map_buffer[i][0]))
		return (error_manager(-14, par));
	if (check_missing_info(par->info) < 0)
		return (error_manager(check_missing_info(par->info), par));
	while (par->map_buffer[i] && par->map_buffer[i][0] == '\0')
		i++;
	return (error_manager(get_map(&par->map_buffer[i], par), par));
}
