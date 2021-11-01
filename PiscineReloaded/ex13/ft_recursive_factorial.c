/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:02:35 by ashatalo          #+#    #+#             */
/*   Updated: 2021/11/01 00:34:37 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb > 12)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		nb = nb * ft_recursive_factorial(nb - 1);
		return (nb);
	}
}
