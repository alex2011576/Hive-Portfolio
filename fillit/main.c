/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:40:22 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 21:17:03 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	usage(void)
{
	ft_putendl("usage:\t number of parameters is not 1");
	return (-1);
}

static int	error(void)
{
	ft_putendl("error");
	return (-1);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_uint16	*tetriminos;
	t_shape		all_shapes[19];
	int			len;

	if (argc != 2)
		return (usage());
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error());
	tetriminos = (t_uint16 *)ft_memalloc(sizeof(t_uint16) * 26);
	if (!tetriminos)
		return (-1);
	fill_tetriminos(all_shapes);
	len = read_tetriminos(fd, tetriminos, all_shapes);
	if (len == -1)
	{
		ft_memdel((void *)&tetriminos);
		close(fd);
		return (error());
	}
	solve(tetriminos, (t_uint8)len);
	return (0);
}
