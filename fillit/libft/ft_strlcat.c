/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:45:30 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/12 18:38:33 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		remain_size;
	const char	*psrc;

	psrc = src;
	remain_size = size;
	while (*dst && remain_size != 0)
	{
		dst++;
		remain_size--;
	}
	dst_len = size - remain_size;
	if (remain_size == 0)
		return (dst_len + ft_strlen(src));
	while (*psrc)
	{
		if (remain_size != 1)
		{
			*dst++ = *psrc;
			remain_size--;
		}
		psrc++;
	}
	*dst = '\0';
	return (dst_len + (size_t)(psrc - src));
}
