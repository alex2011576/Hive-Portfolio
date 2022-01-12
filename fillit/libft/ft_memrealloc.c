/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:44:18 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 14:33:32 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	new = ft_memalloc(new_size);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
