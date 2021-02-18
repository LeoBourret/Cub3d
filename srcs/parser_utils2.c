/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:58:26 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/08 15:00:30 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_size(char **map)
{
	int i;

	i = 0;
	while (map[i] && map[i][0] != '\0')
		i++;
	return (i);
}

void	copy_buffer_into_map(char **map, t_p *par)
{
	int i;

	i = -1;
	while (map[++i] && map[i][0] != '\0')
		par->map[i] = map[i];
	par->map[i] = NULL;
}

void	realloc_map(t_p *par)
{
	int i;
	int j;

	i = -1;
	while (par->map[++i])
	{
		if ((int)ft_strlen(par->map[i]) < par->info->width)
		{
			j = 0;
			while (par->map[i][j])
				j++;
			par->map[i] = ft_realloc(par->map[i], par->info->width);
			par->map_buffer[i] = NULL;
			while (j < par->info->width)
				par->map[i][j++] = '1';
			par->map[i][j] = '\0';
		}
	}
	par->info->height = i;
}

void	refill_map(t_p *par)
{
	int i;
	int j;

	i = -1;
	par->info->width = 0;
	while (par->map[++i])
	{
		j = -1;
		while (par->map[i][++j])
		{
			if (par->map[i][j] == ' ')
				par->map[i][j] = '1';
			else if (is_spawn(par->map[i][j]))
				par->map[i][j] = '0';
		}
		if (par->info->width < j)
			par->info->width = j;
	}
	realloc_map(par);
}

char	*get_data(char *s, t_p *p)
{
	char	*new;
	int		i;
	char	first_c;

	first_c = *s;
	while (*s >= 'A' && *s <= 'Z' && *s)
		s++;
	if (*(s - 1) == 'S' && *s == '2')
		s++;
	if (*s != ' ')
		return (NULL);
	while (*s == ' ')
		s++;
	i = -1;
	while (s[++i])
		if (first_c == 'R' && !((s[i] >= '0'
		&& s[i] <= '9') || (s[i] == ' ')))
			error_manager(-1, p);
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}
