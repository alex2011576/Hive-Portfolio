/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:35:20 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/11 16:37:35 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Returns the smaller of the two values.
 */
int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}
