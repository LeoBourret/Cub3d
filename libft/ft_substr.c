/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:24:08 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:27:14 by jurichar         ###   ########.fr       */
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
		if (!(new = malloc(sizeof(char))))
			return (NULL);
		new[0] = 0;
		return (new);
	}
	size = ft_strlen(&s[start]);
	if (size < len)
		len = size;
	if (!(new = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[start] && (i < len))
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
