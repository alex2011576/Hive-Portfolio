/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:14:25 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/18 17:32:07 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s_dst;
	const char	*s_src;

	s_dst = (char *)dst;
	s_src = (const char *)src;
	if (n && !dst && !src)
		return (NULL);
	while (n--)
		*s_dst++ = *s_src++;
	return (dst);
}
