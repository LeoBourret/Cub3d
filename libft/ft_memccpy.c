/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:22:44 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:25:51 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;
	unsigned char	*ptr_d;

	ptr_s = (unsigned char *)src;
	ptr_d = (unsigned char *)dest;
	i = -1;
	while (++i < n && ptr_s[i] != (unsigned char)c)
		ptr_d[i] = ptr_s[i];
	if (i == n)
		return (NULL);
	ptr_d[i] = ptr_s[i];
	return (&ptr_d[i + 1]);
}
