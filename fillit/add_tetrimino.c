/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:36:58 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 14:30:13 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_uint16	get_shape(t_uint16 num, t_shape *all_shapes)
{
	short	start;
	short	end;
	short	i;

	start = 0;
	end = 19;
	while (start <= end)
	{
		i = (end - start) / 2 + start;
		if (num == all_shapes[i].shape_str)
			return (all_shapes[i].shape_map);
		if (num < all_shapes[i].shape_str)
			end = i - 1;
		else
			start = i + 1;
	}
	return (0);
}

static t_uint16	check_binary(const char *tetrimino, const char *stop)
{
	t_uint16	bin;

	if (!tetrimino)
		return (0);
	bin = 0;
	while (tetrimino != stop && *tetrimino)
	{
		bin <<= 1;
		if (*tetrimino == '#')
			bin |= 1;
		tetrimino++;
	}
	return (bin);
}

int	add_tetrimino(const char *tetri, t_uint16 *tetriminos,
		t_shape *all_shapes, t_uint8 i)
{
	if (i >= 26)
		return (-1);
	if (tetri && ft_strlen(tetri) == 16)
	{
		tetriminos[i] = get_shape(check_binary(ft_strchr(tetri, '#'),
					ft_strrchr(tetri, '#') + 1), all_shapes);
		if (tetriminos[i] == 0)
			return (-1);
	}
	return (0);
}
