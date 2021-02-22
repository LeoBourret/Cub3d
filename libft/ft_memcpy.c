/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:22:56 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:26:04 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!dst && !src)
		return (NULL);
	ptr = (unsigned char *)dst;
	i = -1;
	while (++i < n)
	{
		*ptr = *(unsigned char *)src;
		ptr++;
		src++;
	}
	return (dst);
}
