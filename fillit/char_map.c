/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:52:03 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/22 01:24:25 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	bmap_to_str(char *str, t_uint16 tetrimino, t_tetrimino_info info,
		t_mapinfo mapinfo)
{
	t_uint8	y;
	t_uint8	x;

	y = 0;
	x = 0;
	while (tetrimino != 0)
	{
		if (x > 3)
		{
			y++;
			x = 0;
		}
		if (tetrimino & 1)
		{
			str[((info.coords.y + y) * mapinfo.map_size) - x + info.coords.x]
				= info.id;
		}
		tetrimino >>= 1;
		x++;
	}
}

static void	print_char_map(const char *str, t_mapinfo mapinfo)
{
	t_uint8	i;

	i = 0;
	while (i < mapinfo.map_size)
	{
		write(1, &str[i * mapinfo.map_size], mapinfo.map_size);
		i++;
		ft_putchar('\n');
	}
}

void	write_to_char_map(t_tetrimino_info *tetrimino_info,
		t_mapinfo mapinfo, t_uint16 *tetriminos, t_uint8 len)
{
	t_uint8		i;
	char		*str;

	if (!mapinfo.map)
		return ;
	str = ft_memalloc(sizeof(char) * (mapinfo.map_size * mapinfo.map_size + 1));
	if (!str)
		return ;
	ft_memset(str, '.', mapinfo.map_size * mapinfo.map_size);
	i = 0;
	while (i < len)
	{
		bmap_to_str(str, tetriminos[i], tetrimino_info[i], mapinfo);
		i++;
	}
	print_char_map(str, mapinfo);
	ft_strdel(&str);
}
