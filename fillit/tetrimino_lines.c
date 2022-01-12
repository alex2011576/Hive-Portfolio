/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:38:23 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 01:29:57 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 *	Splits a tetrimino into lines of 4 bits. 
 *	The most significant bit from tetrimino is the last line's last bit.
 *	
 *									0001
 *									0001
 *	0b0000 0011 0001 0001	-->		0011
 *									0000
 *
 * 	INT REPRESENTATION:
 *									1
 *									1
 * 				785			-->		3
 *									0
 *	tetrimino = 4x4 binary representation of the whole tetrimino.
 *
 *	return: array of 4 bits to represent a line.
 */
static t_uint8	*split_tetrimino_to_lines(t_uint16 tetrimino)
{
	t_uint8	*lines;
	t_uint8	i;

	lines = (t_uint8 *)ft_memalloc(sizeof(t_uint8) * 4);
	if (!lines)
		return (NULL);
	i = 0;
	while (tetrimino != 0)
	{
		lines[i] = tetrimino & 0b1111;
		tetrimino >>= 4;
		i++;
	}
	return (lines);
}

/*
 *	Iterates all tetriminos and splits them into lines.
 *
 *	tetrimino = list of tetriminos of size len
 *
 *	return: an array of tetrimino lines
 */
t_uint8	**get_list_of_lines(t_uint16 *tetrimino, t_uint8 len)
{
	t_uint8	i;
	t_uint8	**splitted_tetriminos;

	splitted_tetriminos = (t_uint8 **)malloc(sizeof(t_uint8 *) * (len + 1));
	if (!splitted_tetriminos)
		return (NULL);
	i = 0;
	while (i < len)
	{
		splitted_tetriminos[i] = split_tetrimino_to_lines(tetrimino[i]);
		if (!splitted_tetriminos[i])
		{
			free_array(splitted_tetriminos, i);
			return (NULL);
		}
		i++;
	}
	splitted_tetriminos[i] = NULL;
	return (splitted_tetriminos);
}
