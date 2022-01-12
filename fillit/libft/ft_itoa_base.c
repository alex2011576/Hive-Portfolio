/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:36:27 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/18 14:20:54 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_size(unsigned int n, unsigned int base)
{
	if (n / base == 0)
		return (1);
	return (count_size(n / base, base) + 1);
}

char	*ft_itoa_base(int n, unsigned int base)
{
	unsigned int	remain;
	char			*str;
	size_t			len;

	if (base == 10)
		return (ft_itoa(n));
	if (base < 2 || base > 36)
		return (NULL);
	len = count_size((unsigned int)n, base);
	str = (char *)malloc(sizeof(char) * (size_t)(len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		remain = (unsigned int)n % base;
		if (remain > 9)
			str[len] = (char)(remain - 10 + 'A');
		else
			str[len] = (char)(remain + '0');
		n /= (int)base;
	}
	return (str);
}
