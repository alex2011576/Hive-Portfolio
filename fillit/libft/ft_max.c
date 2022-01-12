/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:35:20 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/11 16:38:17 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Returns the larger of the two values.
 */
int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
