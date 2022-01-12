/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:49:40 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/12 11:59:04 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static void	get_ws_count_be(char const *s, unsigned int *ws_count_b,
		unsigned int *ws_count_e, unsigned int *len)
{
	unsigned int	i;
	int				first_char;

	i = 0;
	first_char = 0;
	while (s[i])
	{
		if (first_char == 0 && !is_whitespace(s[i]))
			first_char = 1;
		else if (first_char == 0)
			(*ws_count_b)++;
		i++;
	}
	*len = i;
	while (first_char && i--)
	{
		if (!is_whitespace(s[i]))
			break ;
		(*ws_count_e)++;
	}
}

char	*ft_strtrim(char const *s)
{
	unsigned int	ws_count_b;
	unsigned int	ws_count_e;
	unsigned int	len;
	char			*ptr;

	if (!s)
		return (NULL);
	ws_count_b = 0;
	ws_count_e = 0;
	get_ws_count_be(s, &ws_count_b, &ws_count_e, &len);
	ptr = (char *)malloc(sizeof(char)
			* (len - ws_count_e - ws_count_b + 1));
	if (!ptr)
		return (NULL);
	ft_strncpy(ptr, &s[ws_count_b], len - ws_count_e - ws_count_b);
	ptr[len - ws_count_e - ws_count_b] = '\0';
	return (ptr);
}
