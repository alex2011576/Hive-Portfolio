/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:38:23 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 14:47:46 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_bitswap(unsigned char octet)
{
	unsigned char	temp;

	temp = 0;
	while (octet != 0)
	{
		temp <<= 4;
		temp |= octet & 0b1111;
		octet >>= 4;
	}
	return (temp);
}
