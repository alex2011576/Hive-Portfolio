/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:48:36 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/18 12:17:40 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
			continue ;
		}
		s++;
	}
	return (count);
}

static unsigned int	len_till_delim(const char **s, char c)
{
	unsigned int	len;

	len = 0;
	while ((*s)[len] != c && (*s)[len])
		len++;
	*s += len;
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	len;
	int				i;

	if (!s)
		return (NULL);
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = len_till_delim(&s, c);
			tab[i] = ft_strnew(len);
			if (!tab[i])
				return (NULL);
			ft_strncpy(tab[i++], s - len, len);
			continue ;
		}
		s++;
	}
	tab[i] = 0;
	return (tab);
}
