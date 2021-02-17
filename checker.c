/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:06:49 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/11 13:40:06 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_error(char **map, int i, int j, int inside)
{
	if ((i == 0 && map[0][j] != ' ' && map[0][j] != '1')
	|| (inside == 1 && (map[i][j] == ' ' || map[i][j] == '\0'))
	|| (inside == 1 && (j == 0 || map[i][j + 1] == '\0'
		|| map[i][j - 1] == ' '))
	||	(inside == 1 && (j > (int)ft_strlen(map[i - 1])))
	|| (inside == 0 && is_map_elem(map[i][j] == 1))
	|| (is_map_elem(map[i][j]) == 1 && map[i][j + 1] == ' ')
	|| (is_map_elem(map[i][j]) == 1 && map[i + 1] && map[i + 1][j] == ' ')
	|| (is_map_elem(map[i][j]) == 1 && (map[i + 1] == NULL
		|| map[i + 1][0] == '\0'))
	|| (map[i][j] == ' ' && (!map[i + 1] || is_map_elem(map[i + 1][j]) == 1)))
		return (0);
	return (1);
}

int		check_file(char *file)
{
	int fd;

	if (ft_strncmp(file + ft_strlen(file) - 4, ".xpm", 4) != 0)
	{
		printf("check file\n");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int		check_missing_info(t_identifier_list *list)
{
	int i;

	i = skip_space(0, list->r);
	i = skip_nb(i, list->r);
	if (!list->r || ft_atoi(list->r) < 1 || ft_atoi(&list->r[i]) < 1)
		return (-1);
	if (!list->no || !check_file(list->no))
		return (-2);
	if (!list->so || !check_file(list->so))
		return (-3);
	if (!list->we || !check_file(list->we))
		return (-4);
	if (!list->ea || !check_file(list->ea))
		return (-5);
	if (!list->s || !check_file(list->s))
		return (-6);
	if (list->s2 && !check_file(list->s2))
		return (-6);
	if (!list->f || !check_rgb(list->f))
		return (-7);
	if (!list->c || !check_rgb(list->c))
		return (-8);
	return (1);
}

void	check_which_info(char *s, t_p *par)
{
	if (*s == 'R')
		par->info->r = get_data(s);
	else if (*s == 'F')
		par->info->f = get_data(s);
	else if (*s == 'C')
		par->info->c = get_data(s);
	else if (*s == 'N' && *(s + 1) == 'O')
		par->info->no = get_data(s);
	else if (*s == 'S' && *(s + 1) == 'O')
		par->info->so = get_data(s);
	else if (*s == 'W' && *(s + 1) == 'E')
		par->info->we = get_data(s);
	else if (*s == 'E' && *(s + 1) == 'A')
		par->info->ea = get_data(s);
	else if (*s == 'S' && *(s + 1) == '2')
		par->info->s2 = get_data(s);
	else if (*s == 'S')
		par->info->s = get_data(s);
}

int		check_rgb(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] && count < 3)
	{
		i = skip_space(i, s);
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		if (ft_atoi(&s[i]) > 255 || ft_atoi(&s[i]) < 0)
			return (0);
		i = skip_nb(i, s);
		count++;
		if (count == 3)
			break ;
		i = skip_space(i, s);
		if (s[i] != ',')
			return (0);
		i++;
	}
	i = skip_space(i, s);
	if (s[i] != '\0')
		return (0);
	return (1);
}
