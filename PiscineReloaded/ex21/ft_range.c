/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:33:18 by aleksei           #+#    #+#             */
/*   Updated: 2021/10/31 19:34:03 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max)
{
    int i;
    int *range;
    i = 0;
    if (min >= max)
        return (NULL);
    range = NULL;
    if (!(range = (int*)malloc(sizeof(int) * (max - min))))
        return (NULL);
    while (min < max)
    {
        range[i] = min;
        min++;
        i++;
    }
    return (range);
}
