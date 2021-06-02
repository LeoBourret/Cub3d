/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:58:26 by lebourre          #+#    #+#             */
/*   Updated: 2021/03/08 11:25:31 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_size(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	copy_buffer_into_map(char **map, t_p *par)
{
	int i;

	i = -1;
	while (map[++i])
	{
		par->map[i] = ft_strdup(map[i]);
		free(map[i]);
		map[i] = NULL;
	}
	par->map[i] = NULL;
}

void	realloc_map(t_p *par)
{
	int i;
	int j;

	i = -1;
	while (par->map[++i])
	{
		par->map[i] = ft_realloc(par->map[i], par->info->width);
		if ((int)ft_strlen(par->map[i]) < par->info->width)
		{
			j = 0;
			while (par->map[i][j])
				j++;
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

char	*get_data(char *s, t_p *p, char *dest, int i)
{
	char	*new;
	char	first_c;

	if (dest)
		free(dest);
	first_c = *s;
	while (*s >= 'A' && *s <= 'Z' && *s)
		s++;
	if (*(s - 1) == 'S' && *s == '2')
		s++;
	if (*s != ' ')
		return (NULL);
	while (*s == ' ')
		s++;
	while (s[++i])
		if (first_c == 'R' && !((s[i] >= '0'
		&& s[i] <= '9') || (s[i] == ' ')))
			error_manager(-1, p);
	if (!(new = malloc(sizeof(char) * (i + 1))))
		error_manager(0, p);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}
