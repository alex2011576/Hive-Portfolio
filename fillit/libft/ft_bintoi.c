/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:14:59 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/12 18:21:51 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bintoi(const char *str)
{
	int		result;
	size_t	len;

	result = 0;
	len = ft_strlen(str);
	while (len--)
	{
		result += (*str - '0') * ft_pow(2, (int)len);
		str++;
	}
	return (result);
}
