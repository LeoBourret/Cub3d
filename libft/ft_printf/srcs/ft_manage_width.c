/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:10:08 by lebourre          #+#    #+#             */
/*   Updated: 2021/06/02 13:25:48 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(int width, int src_len, int zero)
{
	int	printed_char;

	printed_char = 0;
	while (width - src_len > 0)
	{
		if (zero)
			printed_char += ft_putchar_ret('0');
		else
			printed_char += ft_putchar_ret(' ');
		width--;
	}
	return (printed_char);
}
