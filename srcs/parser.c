/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:49:10 by lebourre          #+#    #+#             */
/*   Updated: 2021/03/08 11:52:59 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_spawn_info(char **map, int i, int j, t_p *par)
{
	par->info->spawn_dir = (int)map[i][j];
	par->info->spawn_coord[0] = j;
	par->info->spawn_coord[1] = i;
}

int		set_inside(char **map, int i, int j, int inside)
{
	if (inside == 0 && (map[i][j] == '0' || is_spawn(map[i][j])
	|| map[i][j] == '2' || map[i][j] == '3'))
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
	par->map[i] = NULL;
	while (map[i][++j])
	{
		inside = set_inside(map, i, j, inside);
		if (!is_map_elem(map[i][j]))
			error_manager(10, par);
		if (!check_map_error(map, i, j, inside))
			error_manager(11, par);
		if ((is_spawn(map[i][j])) && par->info->spawn_dir == 0)
			set_spawn_info(map, i, j, par);
		else if (is_spawn(map[i][j]) && par->info->spawn_dir > 0)
			error_manager(12, par);
		if (map[i][j] == '2' || map[i][j] == '3')
			par->info->sp_nb++;
	}
	return (1);
}

int		get_map(char **map, t_p *par)
{
	int i;

	par->info->spawn_dir = 0;
	par->info->sp_nb = 0;
	i = 0;
	while (map[i] && map[i][0])
		i++;
	if (!map[0] || !map)
		return (-9);
	if (!(par->map = malloc(sizeof(char *) * i + 1)))
		return (0);
	i = -1;
	while (map[++i] && map[i][0])
	{
		par->info->height = i;
		check_line(map, i, par);
		par->map[i] = ft_strdup(map[i]);
	}
	par->map[i] = NULL;
	if (map[i] && map[i][0] == '\0')
		check_buffer_rest(&map[i], par);
	if (par->info->spawn_dir == 0)
		return (-13);
	refill_map(par);
	return (1);
}

int		manage_map(int fd, t_p *par, int i, int j)
{
	int ret;

	par->map_buffer = ft_realloc_double(par->map_buffer);
	while ((ret = get_next_line(fd, &par->map_buffer[++i])) > 0)
		par->map_buffer = ft_realloc_double(par->map_buffer);
	if (ret < 0)
		return (error_manager(19, par));
	else
	{
		free(par->map_buffer[i]);
		par->map_buffer[i] = NULL;
	}
	par->buff_size = map_size(par->map_buffer);
	while (par->map_buffer[++j] != NULL
	&& (is_identifier(par->map_buffer[j]) || par->map_buffer[j][0] == '\0'))
		if (is_identifier(par->map_buffer[j]))
			check_which_info(par->map_buffer[j], par, j);
	if (par->map_buffer[j] != NULL && (!is_identifier(par->map_buffer[j])
	&& par->map_buffer[j][0] != '\0') && !is_map_elem(par->map_buffer[j][0]))
		return (error_manager(-14, par));
	if (check_missing_info(par->info) < 0)
		return (error_manager(check_missing_info(par->info), par));
	while (par->map_buffer[j] && par->map_buffer[j][0] == '\0')
		j++;
	return (error_manager(get_map(&par->map_buffer[j], par), par));
}
