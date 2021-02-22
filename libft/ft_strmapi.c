/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:23:55 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:27:02 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = -1;
	if (!(new = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		new[i] = f(i, s[i]);
	new[i] = '\0';
	return (new);
}
