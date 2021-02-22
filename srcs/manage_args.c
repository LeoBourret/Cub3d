/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:03:44 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:28:35 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
		return (0);
	close(fd);
	return (1);
}

void	manage_args(int ac, char **av, t_p *par)
{
	if (ac == 2)
	{
		if (!check_map_file(av[1]))
			error_manager(15, par);
		if (!(par->save = malloc(sizeof(t_save))))
			error_manager(0, par);
		par->save->save = 0;
	}
	else if (ac == 3)
	{
		if (!check_map_file(av[1]))
			error_manager(15, par);
		if (ft_strncmp(av[2], "--save", ft_strlen("--save")) != 0)
			error_manager(16, par);
		if (!(par->save = malloc(sizeof(t_save))))
			error_manager(0, par);
		par->save->save = 1;
	}
	else if (ac < 2 || ac > 3)
	{
		if (ac < 2)
			error_manager(17, par);
		if (ac > 3)
			error_manager(18, par);
	}
}
