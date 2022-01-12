/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:00:23 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/18 12:30:21 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_addr(size_t addr)
{
	size_t	remain;

	remain = addr % 16;
	addr /= 16;
	if (addr != 0)
		print_addr(addr);
	if (remain > 9)
		ft_putchar((char)(remain - 10 + 'a'));
	else
		ft_putchar((char)(remain + '0'));
}

void	ft_putaddr(void *ptr)
{
	size_t	addr;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return ;
	}
	addr = (size_t)ptr;
	ft_putstr("0x");
	print_addr(addr);
}
