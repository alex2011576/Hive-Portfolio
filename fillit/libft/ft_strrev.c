/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:23:43 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/12 18:25:02 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *a, char *b)
{
	char	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_strrev(char *str)
{
	size_t	start_i;
	size_t	end_i;

	start_i = 0;
	end_i = ft_strlen(str) - 1;
	while (start_i < end_i)
	{
		ft_swap(str + start_i, str + end_i);
		end_i--;
		start_i++;
	}
}
