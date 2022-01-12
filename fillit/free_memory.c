/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:58:40 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 16:23:21 by ashatalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 *	Goes through the array and frees all the allocated memory.
 */
void	free_array(t_uint8 **arr, t_uint8 len)
{
	t_uint8	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	exit_status(void *ptr1, void *ptr2, void *ptr3, int status)
{
	ft_memdel(&ptr1);
	ft_memdel(&ptr2);
	ft_memdel(&ptr3);
	exit(status);
}
