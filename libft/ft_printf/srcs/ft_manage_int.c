/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:09:32 by lebourre          #+#    #+#             */
/*   Updated: 2021/06/02 13:24:04 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_abs(long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_print_int(char *str, t_flags flags, long nb, int len_nb)
{
	int	printed_char;

	printed_char = 0;
	if (flags.minus == 0
		&& (flags.zero == 0 || (flags.zero == 1 && flags.dot > -1)))
		printed_char += ft_print_width(flags.width, len_nb, 0);
	if (nb < 0)
		printed_char += ft_putchar_ret('-');
	if (flags.minus == 0 && flags.zero == 1 && flags.dot == -1)
		printed_char += ft_print_width(flags.width, len_nb, 1);
	printed_char += ft_print_width(flags.dot, ft_nblen(ft_abs(nb)), 1);
	printed_char += ft_putstr_ret(str);
	if (flags.minus == 1)
		printed_char += ft_print_width(flags.width, len_nb, flags.zero);
	return (printed_char);
}

int	ft_manage_int(int n, t_flags flags)
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
