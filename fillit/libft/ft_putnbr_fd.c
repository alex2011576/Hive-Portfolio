/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:56:48 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/05 14:44:39 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_putnbr_fd(int nb, int fd)
{
	int	remain;

	remain = (nb % 10);
	nb /= 10;
	if (remain < 0)
	{
		ft_putchar_fd('-', fd);
		remain *= -1;
		nb *= -1;
	}
	if (nb != 0)
		ft_putnbr_fd(nb, fd);
	ft_putchar_fd((char)(remain + '0'), fd);
}
