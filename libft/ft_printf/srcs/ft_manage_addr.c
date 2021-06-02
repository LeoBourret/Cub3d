/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:08:50 by lebourre          #+#    #+#             */
/*   Updated: 2021/06/02 14:27:14 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	while (str[j])
		j++;
	i = -1;
	while (++i < --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	return (str);
}

char	*ft_get_addr(unsigned long long addr, t_flags flags)
{
	char	*str_addr;
	int		i;

	i = 0;
	str_addr = malloc(sizeof(char) * find_size((long int)addr + 1));
	if (str_addr == NULL)
		return (NULL);
	while (addr > 0)
	{
		str_addr[i] = addr % 16;
		if (str_addr[i] < 10)
			str_addr[i] += '0';
		else
			(str_addr[i] += 87);
		addr /= 16;
		i++;
	}
	while (i < flags.dot)
		str_addr[i++] = '0';
	ft_strlcat(str_addr, "x0", find_size((long int)addr + 1));
	str_addr = ft_reverse(str_addr);
	return (str_addr);
}

char	*ft_addr_null(t_flags flags)
{
	char	*addr;
	int		i;

	i = -1;
	if (flags.dot < 0)
	{
		addr = malloc(sizeof(char) * 4);
		if (addr == NULL)
			return (NULL);
		addr[0] = '\0';
		ft_strlcat(addr, "0x0", 4);
		return (addr);
	}
	addr = malloc(sizeof(char) * (3 + flags.dot));
	if (addr)
		return (NULL);
	addr[0] = '0';
	addr[1] = 'x';
	while (++i < flags.dot)
		addr[i + 2] = '0';
	addr[i + 2] = '\0';
	return (addr);
}

int	ft_manage_addr(unsigned long long addr, t_flags flags)
{
	char	*str_addr;
	int		printed;

	printed = 0;
	if (!addr)
		str_addr = ft_addr_null(flags);
	else
		str_addr = ft_get_addr(addr, flags);
	if (flags.minus == 0)
		printed += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	printed += ft_putstr_ret(str_addr);
	if (flags.minus == 1)
		printed += ft_print_width(flags.width, ft_strlen(str_addr), 0);
	free(str_addr);
	return (printed);
}
