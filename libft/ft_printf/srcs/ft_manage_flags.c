/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:09:14 by lebourre          #+#    #+#             */
/*   Updated: 2021/06/02 13:22:18 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(int c)
{
	if (c == '.' || c == '-' || c == '*')
		return (1);
	return (0);
}

void	ft_flag_width(t_flags *flags, va_list args)
{
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
		flags->zero = 0;
	}
}

void	ft_flag_digit(char digit, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = flags->width * 10 + (digit - '0');
}

void	ft_flag_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

int	ft_flag_dot(const char *format, int i, t_flags *flags, va_list args)
{
	i++;
	if (format[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(format[i]))
		{
			flags->dot = flags->dot * 10 + (format[i] - '0');
			i++;
		}
	}
	return (i);
}
