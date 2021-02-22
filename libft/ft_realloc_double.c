/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:41:01 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:26:33 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_double(char **str)
{
	char	**new;
	int		i;

	if (!str)
	{
		if (!(new = malloc(sizeof(char *) * 2)))
			return (NULL);
		new[0] = NULL;
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
