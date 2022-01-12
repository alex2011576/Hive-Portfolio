/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:47:47 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/12 13:22:01 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(const char *str)
{
	return (*str == '-' && ft_isdigit(*(str + 1)));
}

int	ft_atoi(const char *str)
{
	int	negative;
	int	result;

	negative = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (is_negative(str))
	{
		negative = -1;
		str++;
	}
	else if (*str == '+' && ft_isdigit(*(str + 1)))
		str++;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * negative);
}
