/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:23:31 by lebourre          #+#    #+#             */
/*   Updated: 2021/03/08 11:23:55 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**gen_error_list_re(char **error)
{
	error[9] = "Error\nmap not found in the .cube file\n";
	error[10] = "Error\nmap is not set properly\n";
	error[11] = "Error\nmap is not closed properly or none wall bloc is \
in contact with a space character\n";
	error[12] = "Error\nmultiple spawn point found in the map\n";
	error[13] = "Error\nspawn point not found in the map\n";
	error[14] = "Error\nunknown identifier is set\n";
	error[15] = "Error\nincorrect .cub map\n";
	error[16] = "Error\nunknown argument\n";
	error[17] = "Error\nmap not given during execution\n";
	error[18] = "Error\ntoo many argument\n";
	error[19] = "Error\ncannot read file\n";
	error[20] = "Error\ncannot write in save file\n";
	error[21] = "Error\ncannot load xpm file\n";
	error[22] = "Error\ncontent found after map\n";
	error[23] = NULL;
	return (error);
}

char	**gen_error_list(void)
{
	char **error;

	if (!(error = malloc(sizeof(char *) * 25)))
		return (NULL);
	error[0] = "Error\nmalloc can't allocate the memory\n";
	error[1] = "Error\nresolution not set or not setp properly. \
Resolution can only contain numbers and spaces\n";
	error[2] = "Error\nnorth texture path not set or incorrect\n";
	error[3] = "Error\nsouth texture path not set or incorrect\n";
	error[4] = "Error\nwest texture path not set or incorrect\n";
	error[5] = "Error\neast texture path not set or incorrect\n";
	error[6] = "Error\nsprite texture path not set or incorrect\n";
	error[7] = "Error\nfloor color not set or incorrect. RGB must \
contain three numbers between 0 - 255, and comma in between (spaces are \
allowed, but commas are mandatory).\n";
	error[8] = "Error\nceilling color not set or incorrect. \
RGB must contain three numbers between 0 - 255, and one comma in between \
(spaces are allowed, but commas are mandatory).\n";
	return (gen_error_list_re(error));
}

int		error_manager(int error, t_p *par)
{
	char	**s_error;

	(void)par;
	if (error == 1)
		return (1);
	s_error = gen_error_list();
	if (error < 0)
		error *= -1;
	ft_putstr_fd(s_error[error], 1);
	free(s_error);
	s_error = NULL;
	free_prog(par);
	exit(0);
	return (0);
}
