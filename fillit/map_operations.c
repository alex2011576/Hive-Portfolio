/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:33:27 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/23 00:37:36 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 *	Tries to fit one line from the tetrimino to one line of the map.
 *	NOTE: Origin of the tetrimino is on the right side.
 *			1111
 *			   ^
 *			origin
 *
 *	x_offset = 	times to left shift the line.
 *
 *	return:		1 or 0 depending on whether the line 
 *				can be placed into the map.
 */
int	try_line(int line, int map, t_uint8 x_offset, t_uint8 map_size)
{
	line <<= x_offset;
	return (!(line & map) && line < (1 << map_size));
}

/*
 *	Removes a tetrimino from the map.
 */
void	remove_shape(t_uint8 *lines, int *map,
			t_coords coords, t_uint8 map_size)
{
	t_uint8	i;
	t_uint8	x_offset;

	x_offset = map_size - coords.x - 1;
	i = 0;
	while (i < 4)
	{
		if (!lines[i])
			return ;
		map[coords.y + i] ^= lines[i] << x_offset;
		i++;
	}
}

/*
 *	Adds a tetrimino to the map.
 */
void	add_shape(t_uint8 *lines, int *map, t_coords coords, t_uint8 map_size)
{
	t_uint8	i;
	t_uint8	x_offset;

	x_offset = map_size - coords.x - 1;
	i = 0;
	while (i < 4)
	{
		if (!lines[i])
			return ;
		map[coords.y + i] |= lines[i] << x_offset;
		i++;
	}
}

/*
 *	Iterates all the lines of the terimino.
 *	Checks if the tetrimino can be placed to the map.
 *
 *	return:	1 or 0 depending on whether the 
 *			tetrimino can be placed on the map.
 */
int	try_shape(t_uint8 *lines, int *map, t_coords coords, t_uint8 map_size)
{
	t_uint8	i;

	i = 0;
	while (i < 4)
	{
		if (!lines[i])
			return (1);
		if (coords.y + i >= map_size || coords.y + i < 0)
			return (0);
		if (!try_line(lines[i],
				map[coords.y + i], map_size - coords.x - 1, map_size))
			return (0);
		i++;
	}
	return (1);
}
