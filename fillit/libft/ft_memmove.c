/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:13:32 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/18 17:38:41 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	const char	*psrc;
	int			diff;

	if (len && !dst && !src)
		return (NULL);
	pdst = (char *)dst;
	psrc = (const char *)src;
	diff = (int)(pdst - psrc);
	if (diff > 0 && pdst < psrc + len)
	{
		while (len > 0)
		{
			len--;
			pdst[len] = psrc[len];
		}
	}
	else
		while (len--)
			*pdst++ = *psrc++;
	return (dst);
}
