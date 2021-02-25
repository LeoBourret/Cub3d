/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:51:21 by lebourre          #+#    #+#             */
/*   Updated: 2021/02/19 10:28:42 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_identifier(char *s)
{
	if (*s == 'S' || (*s == 'S' && *(s + 1) == '2')
	|| (*s == 'N' && *(s + 1) == 'O') || (*s == 'S' && *(s + 1) == 'O')
	|| (*s == 'W' && *(s + 1) == 'E') || (*s == 'E' && *(s + 1) == 'A'))
		return (1);
	else if (*s == 'R' || *s == 'F' || *s == 'C')
		return (2);
	return (0);
}

int		skip_space(int i, char *s)
{
	while (s[i] && s[i] == ' ')
		i++;
	return (i);
}

int		skip_nb(int i, char *s)
{
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

int		is_map_elem(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0' || c == '2'
		|| c == '3')
		return (1);
	if (c == '1' || c == ' ')
		return (2);
	return (0);
}

int		is_spawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
