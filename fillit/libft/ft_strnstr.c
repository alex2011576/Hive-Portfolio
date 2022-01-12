/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:51:03 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/12 13:16:56 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;

	if (!*needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (*haystack && n >= len)
	{
		if (*needle == *haystack
			&& ft_strncmp(needle, haystack, len) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
