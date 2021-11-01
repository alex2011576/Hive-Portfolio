/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:37:59 by aleksei           #+#    #+#             */
/*   Updated: 2021/10/31 22:59:17 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_if(char **tab, int(*f)(char*))
{
    int i;
    int k;

    i = 0;
    k = 0;
    while(tab[i])
    {
        if (f(tab[i]) == 1)
            k++;
        i++;
    }
    return (k);
}