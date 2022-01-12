/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:13:18 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/23 00:16:06 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fill_tetriminos_str(t_shape *tetriminos)
{
	tetriminos[0].shape_str = 0b1111;
	tetriminos[18].shape_str = 0b1000100010001;
	tetriminos[2].shape_str = 0b11011;
	tetriminos[16].shape_str = 0b1000110001;
	tetriminos[8].shape_str = 0b1100011;
	tetriminos[10].shape_str = 0b10011001;
	tetriminos[6].shape_str = 0b111001;
	tetriminos[4].shape_str = 0b100111;
	tetriminos[12].shape_str = 0b100011001;
	tetriminos[13].shape_str = 0b100110001;
	tetriminos[15].shape_str = 0b1000100011;
	tetriminos[17].shape_str = 0b1100010001;
	tetriminos[1].shape_str = 0b10111;
	tetriminos[3].shape_str = 0b11101;
	tetriminos[5].shape_str = 0b110011;
	tetriminos[11].shape_str = 0b100010011;
	tetriminos[14].shape_str = 0b110010001;
	tetriminos[7].shape_str = 0b1000111;
	tetriminos[9].shape_str = 0b1110001;
}

static void	fill_tetriminos_map(t_shape *tetriminos)
{
	tetriminos[0].shape_map = 0b1111;
	tetriminos[18].shape_map = 0b1000100010001;
	tetriminos[2].shape_map = 0b1100011;
	tetriminos[16].shape_map = 0b100110010;
	tetriminos[8].shape_map = 0b110110;
	tetriminos[10].shape_map = 0b1000110001;
	tetriminos[6].shape_map = 0b100111;
	tetriminos[4].shape_map = 0b1110010;
	tetriminos[12].shape_map = 0b1000110010;
	tetriminos[13].shape_map = 0b100110001;
	tetriminos[15].shape_map = 0b1100100010;
	tetriminos[17].shape_map = 0b100010011;
	tetriminos[1].shape_map = 0b1110001;
	tetriminos[3].shape_map = 0b1000111;
	tetriminos[5].shape_map = 0b110011;
	tetriminos[11].shape_map = 0b1100010001;
	tetriminos[14].shape_map = 0b1000100011;
	tetriminos[7].shape_map = 0b1110100;
	tetriminos[9].shape_map = 0b10111;
}

void	fill_tetriminos(t_shape *tetriminos)
{
	fill_tetriminos_str(tetriminos);
	fill_tetriminos_map(tetriminos);
}
