/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:09:59 by lebourre          #+#    #+#             */
/*   Updated: 2021/06/02 13:25:40 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_manage_uint(unsigned int n, t_flags flags)
{
	int		printed_char;
	int		len_nb;
	char	*str;

	printed_char = 0;
	if (n == 0 && flags.dot == 0)
	{
		printed_char += ft_print_width(flags.width, 0, 0);
		return (printed_char);
	}
	str = ft_itoa_pft(n);
	if (flags.dot > ft_nblen(ft_abs(n)))
		len_nb = ft_nblen(n) + (flags.dot - ft_nblen(ft_abs(n)));
	else
		len_nb = ft_nblen(n);
	printed_char = ft_print_int(str, flags, n, len_nb);
	free(str);
	return (printed_char);
}
