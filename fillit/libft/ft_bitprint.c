/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:48:45 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 15:06:08 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitprint(unsigned char octet)
{
	size_t	count;

	count = 8;
	octet = (unsigned char)ft_bitrev((int)octet);
	while (count--)
	{
		if (octet & 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		octet >>= 1;
	}
}
