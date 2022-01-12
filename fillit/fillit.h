/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:15 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 14:30:47 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef unsigned short	t_uint16;
typedef unsigned char	t_uint8;

typedef struct s_coords
{
	t_uint8	x;
	t_uint8	y;
}	t_coords;

typedef struct s_shape
{
	t_uint16	shape_str;
	t_uint16	shape_map;
}	t_shape;

typedef struct s_mapinfo
{
	t_uint8	map_size;
	int		*map;
}	t_mapinfo;

typedef struct s_tetrimino_info
{
	char		id;
	t_coords	coords;
}	t_tetrimino_info;

void	solve(t_uint16 *tetriminos, t_uint8 len);
void	fill_tetriminos(t_shape *tetriminos);
int		read_tetriminos(const int fd, t_uint16 *tetriminos,
			t_shape *all_shapes);
int		add_tetrimino(const char *tetri, t_uint16 *tetriminos,
			t_shape *all_shapes, t_uint8 i);
void	remove_shape(t_uint8 *lines, int *map, t_coords coords,
			t_uint8 map_size);
void	add_shape(t_uint8 *lines, int *map, t_coords coords, t_uint8 map_size);
int		try_shape(t_uint8 *lines, int *map, t_coords coords, t_uint8 map_size);
int		try_line(int line, int map, t_uint8 x_offset, t_uint8 map_size);
t_uint8	**get_list_of_lines(t_uint16 *tetrimino, t_uint8 len);
void	write_to_char_map(t_tetrimino_info *tetrimino_info,
			t_mapinfo mapinfo, t_uint16 *tetriminos, t_uint8 len);
void	exit_status(void *ptr1, void *ptr2, void *ptr3, int status);
void	free_array(t_uint8 **arr, t_uint8 len);

#endif
