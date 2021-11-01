/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:34:57 by aleksei           #+#    #+#             */
/*   Updated: 2021/10/31 18:28:03 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strdup(char *src)
{
    char    *buf;
    int     i;

    i = 0;
    while(src[i])
        i++;
    buf = NULL;
    if (!(buf = (char*)malloc(sizeof(char) * (i + 1))))
        return ("Error");
    buf[i] = '\0';
    i--;
    while (i >= 0)
    {
        buf[i] = src[i];
        i--;
    }
    return (buf);
}
