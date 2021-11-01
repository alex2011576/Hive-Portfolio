/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashatalo <ashatalo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:02:35 by ashatalo          #+#    #+#             */
/*   Updated: 2021/10/29 21:31:42 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb > 12)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		nb = nb * ft_iterative_factorial(nb - 1);
		return (nb);
	}
}
