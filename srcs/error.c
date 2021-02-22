/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:32:39 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/19 10:27:59 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**gen_error_list_re(char **error)
{
	error[9] = "Error: map not found in the .cube file\n";
	error[10] = "Error: map is not set properly\n";
	error[11] = "Error: map is not closed properly\n";
	error[12] = "Error: multiple spawn point found in the map\n";
	error[13] = "Error: spawn point not found in the map\n";
	error[14] = "Error: unknown identifier is set\n";
	error[15] = "Error: incorrect .cub map\n";
	error[16] = "Error: unknown argument\n";
	error[17] = "Error: map not given during execution\n";
	error[18] = "Error: too many argument\n";
	error[19] = "Error: cannot read file\n";
	error[20] = "Error: cannot write in save file\n";
	error[21] = "Error: cannot load xpm file\n";
	error[22] = NULL;
	return (error);
}

char	**gen_error_list(void)
{
	char **error;

	if (!(error = malloc(sizeof(char *) * 23)))
		return (NULL);
	error[0] = "Error: malloc can't allocate the memory\n";
	error[1] = "Error: resolution not set or not setp properly. \
	Resolution can only contain numbers and spaces\n";
	error[2] = "Error: north texture path not set or incorrect\n";
	error[3] = "Error: south texture path not set or incorrect\n";
	error[4] = "Error: west texture path not set or incorrect\n";
	error[5] = "Error: east texture path not set or incorrect\n";
	error[6] = "Error: sprite texture path not set or incorrect\n";
	error[7] = "Error: floor color not set or incorrect. RGB must \
	contain numbers, and comma in between (spaces are allowed, \
	but commas are mandatory).\n";
	error[8] = "Error: ceilling color not set or incorrect. \
	RGB must contain numbers, and one comma in between \
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
	ft_putstr_fd(s_error[error], 0);
	free(s_error);
	s_error = NULL;
	free_prog(par);
	exit(0);
	return (0);
}
