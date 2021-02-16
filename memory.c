/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:01:10 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/01 16:01:31 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_realloc(char **str)
{
	char	**new;
	int		i;

	if (!str)
	{
		if (!(new = malloc(sizeof(char *) * 2)))
			return (NULL);
		new[1] = NULL;
		return (new);
	}
	i = 0;
	while (str[i])
		i++;
	if (!(new = malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = -1;
	while (str[++i])
	{
		new[i] = ft_strdup(str[i]);
		free(str[i]);
	}
	new[i + 1] = NULL;
	free(str);
	return (new);
}
