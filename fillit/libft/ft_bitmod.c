/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:07:58 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 15:38:23 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_bitmod(unsigned char octet, unsigned char place,
		unsigned char bin)
{
	unsigned char	temp;

	temp = 1 << place;
	octet &= ~temp;
	octet |= bin << place;
	return (octet);
}
