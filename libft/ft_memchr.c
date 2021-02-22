/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:22:49 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:25:54 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n <= 0)
		return (NULL);
	while (i < n - 1 && ptr[i] != (unsigned char)c)
		i++;
	if (ptr[i] == (unsigned char)c)
		return (&ptr[i]);
	return (NULL);
}
