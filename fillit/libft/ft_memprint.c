/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:14:26 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/05 13:26:14 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Prints the ASCII values of the mem area
 */
void	ft_memprint(const void *mem, size_t size)
{
	const unsigned char	*pmem;

	pmem = (const unsigned char *)mem;
	while (size--)
	{
		ft_putnbr((int)*pmem);
		ft_putchar(' ');
		pmem++;
	}
}
