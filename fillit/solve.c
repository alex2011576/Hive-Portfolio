/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:33 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/23 00:53:42 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(int map_size, int *map)
{
	int		i;
	size_t	len;
	char	*str;

	i = 0;
	while (i < map_size)
	{
		str = ft_itoa_base(map[i], 2);
		len = ft_strlen(str);
		while (len < (size_t)map_size)
		{
			write(1, "0", 1);
			len++;
		}
		ft_putendl(str);
		ft_strdel(&str);
		i++;
	}
}
static int	update_best(t_tetrimino_info *info, t_uint8 *i, t_coords coords)
{
	info[*i - 1].coords = coords;
	(*i)--;
	return (1);
}

int	find_solution(t_uint8 **lines, t_tetrimino_info *info, t_mapinfo *minfo)
{
	static t_uint8	i;
	t_coords		coords;

	if (lines[i] == NULL)
		return (1);
	coords.y = 0;
	while (coords.y < minfo->map_size)
	{
		coords.x = 0;
		while (coords.x < minfo->map_size)
		{
			if (try_shape(lines[i], minfo->map, coords, minfo->map_size))
			{
				add_shape(lines[i], minfo->map, coords, minfo->map_size);
				i++;
				if (find_solution(lines, info, minfo))
					return (update_best(info, &i, coords));
				i--;
				remove_shape(lines[i], minfo->map, coords, minfo->map_size);
			}
			coords.x++;
		}
		coords.y++;
	}
	return (0);
}

t_tetrimino_info	*fill_ids(t_uint8 len)
{
	t_tetrimino_info	*tinfo;
	t_uint8				i;

	i = 0;
	tinfo = (t_tetrimino_info *)ft_memalloc(sizeof(*tinfo) * len);
	if (!tinfo)
		return (NULL);
	while (i < len)
	{
		tinfo[i].id = 'A' + i;
		tinfo[i].coords.x = 0;
		tinfo[i].coords.y = 0;
		i++;
	}
	return (tinfo);
}

void	solve(t_uint16 *tetriminos, t_uint8 len)
{
	t_mapinfo			minfo;
	t_uint8				**tetriminos_lines;
	t_tetrimino_info	*info;

	minfo.map_size = (t_uint8)ft_sqrt(len * 4);
	minfo.map = (int *)ft_memalloc(sizeof(int) * minfo.map_size);
	tetriminos_lines = get_list_of_lines(tetriminos, len);
	info = fill_ids(len);
	if (!info || !minfo.map || !tetriminos_lines)
	{
		free_array(tetriminos_lines, len);
		exit_status((void *)info, (void *)minfo.map, (void *)tetriminos, -1);
	}
	while (!find_solution(tetriminos_lines, info, &minfo))
	{
		minfo.map_size++;
		minfo.map = (int *)ft_memrealloc(minfo.map,
				(minfo.map_size - 1) * sizeof(int),
				minfo.map_size * sizeof(int));
		if (!minfo.map)
			break ;
	}
	write_to_char_map(info, minfo, tetriminos, len);
	free_array(tetriminos_lines, len);
	exit_status((void *)info, (void *)minfo.map, (void *)tetriminos, 0);
}
