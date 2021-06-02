/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:41:01 by lebourre          #+#    #+#             */
/*   Updated: 2021/05/25 14:46:10 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_double(char **str)
{
	char	**new;
	int		i;

	if (!str)
	{
		new = malloc(sizeof(char *) * 2);
		if (new == NULL)
			return (NULL);
		new[0] = NULL;
		new[1] = NULL;
		return (new);
	}
	new = malloc(sizeof(char *) * (ft_double_strlen(str) + 2));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		new[i] = ft_strdup(str[i]);
		free(str[i]);
	}
	new[i] = NULL;
	new[i + 1] = NULL;
	free(str);
	return (new);
}
