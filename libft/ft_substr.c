/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:24:08 by lebourre          #+#    #+#             */
/*   Updated: 2021/05/25 14:54:44 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	size;

	if (start >= ft_strlen(s) || !s)
	{
		new = malloc(sizeof(char));
		if (new == NULL)
			return (NULL);
		new[0] = 0;
		return (new);
	}
	size = ft_strlen(&s[start]);
	if (size < len)
		len = size;
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[start] && (i < len))
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
