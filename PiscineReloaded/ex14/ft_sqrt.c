/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:45:33 by aleksei           #+#    #+#             */
/*   Updated: 2021/10/31 12:34:47 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_calculus(int min, int max, int nb)
{
	int	check;
	int	a;
	
	a = 46340 / 2; 
	while (nb != a * a)
	{ 
		check = a;
		if (nb > a * a)
		{ 
			min = a;
			a = a + (max - a) / 2;
		}
		else
		{
			max = a; 
			a = a - (a - min) / 2;
		}
		if (check == a)
			return (0);
	}
	return (a);	
}
int ft_sqrt(int nb)
{
	int	min;
	int	max;

	min = 0;
	max = 46340;
	if (nb <= 0)
		return (0);
	if (nb == 2147395600)
		return (46340);
	return (ft_calculus(min, max, nb));
}
