/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:45:40 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 15:46:30 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_bitrev(unsigned char octet)
{
	size_t			count;
	unsigned char	temp;

	count = 8;
	temp = 0;
	while (count--)
	{
		temp <<= 1;
		temp |= octet & 1;
		octet >>= 1;
	}
	return (temp);
}
