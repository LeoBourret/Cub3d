/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:09:53 by lebourre          #+#    #+#             */
/*   Updated: 2021/06/02 13:25:26 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_istype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%' || c == 'n')
		return (1);
	return (0);
}

int	ft_manage_type_2(int c, va_list args, t_flags flags, int printed)
{
	int	*ptr_n;

	(void)flags;
	ptr_n = 0;
	if (c == 'n')
	{
		ptr_n = va_arg(args, int *);
		*ptr_n = printed;
	}
	else if (c == 'e')
		printed = 1;
	else if (c == 'g')
		printed = 1;
	return (printed);
}

int	ft_manage_type(int c, va_list args, t_flags flags, int printed)
{
	if (c == 'd' || c == 'i')
		printed += ft_manage_int(va_arg(args, int), flags);
	else if (c == 'u')
		printed += ft_manage_uint(va_arg(args, int), flags);
	else if (c == 'c')
		printed += ft_manage_char(va_arg(args, int), flags);
	else if (c == 's')
		printed += ft_manage_str(va_arg(args, char *), flags);
	else if (c == 'x')
		printed += ft_manage_hex(va_arg(args, unsigned int), flags, 1);
	else if (c == 'X')
		printed += ft_manage_hex(va_arg(args, unsigned int), flags, 0);
	else if (c == 'p')
		printed += ft_manage_addr(va_arg(args, unsigned long long int), flags);
	else if (c == '%')
		printed += ft_manage_percent(flags);
	else
		printed += ft_manage_type_2(c, args, flags, printed);
	return (printed);
}
