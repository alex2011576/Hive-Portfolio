/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:07:21 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/15 12:41:15 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_nums(int n, size_t count, int negative)
{
	if (negative)
	{
		if (n > -10)
			return (1 + count + 1);
		return (count_nums(n / 10, count + 1, negative));
	}
	else
	{
		if (n < 10)
			return (1 + count);
		return (count_nums(n / 10, count + 1, negative));
	}
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;
	int		negative;
	int		result;

	negative = n < 0;
	count = count_nums(n, 0, negative);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (negative)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[count] = '\0';
	while (n != 0)
	{
		count--;
		result = n % 10;
		result = ft_abs(result);
		str[count] = (char)(result + '0');
		n /= 10;
	}
	return (str);
}
