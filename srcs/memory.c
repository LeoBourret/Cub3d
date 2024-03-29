/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:01:10 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/19 10:28:27 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_info_to_null(t_p *p)
{
	t_identifier_list	*list;

	if (!(list = malloc(sizeof(t_identifier_list))))
		error_manager(0, p);
	p->info = list;
	p->info->r = NULL;
	p->info->no = NULL;
	p->info->so = NULL;
	p->info->we = NULL;
	p->info->ea = NULL;
	p->info->s = NULL;
	p->info->s2 = NULL;
	p->info->f = NULL;
	p->info->c = NULL;
}

void	*ft_malloc(int size, t_p *p)
{
	void *ptr;

	if (!(ptr = malloc(size)))
		error_manager(0, p);
	return (ptr);
}
