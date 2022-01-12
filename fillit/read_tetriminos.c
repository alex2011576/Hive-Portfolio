/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:22:27 by jlehtine          #+#    #+#             */
/*   Updated: 2021/12/23 00:48:13 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	line_check(char *line)
{
	t_uint8	len;

	len = 0;
	while (line[len])
	{
		if (len > 3 || !(line[len] == '.' || line[len] == '#'))
			return (-1);
		len++;
	}
	if (len != 4)
		return (-1);
	return (0);
}

static int	create_tetrimino(char *line, char **tetri)
{
	char	*tmp;

	if (!*tetri)
	{
		*tetri = ft_strdup(line);
		if (!*tetri)
			return (-1);
	}
	else
	{
		tmp = ft_strjoin(*tetri, line);
		if (!tmp)
			return (-1);
		free(*tetri);
		*tetri = tmp;
	}
	return (0);
}

static int	validate_tetrimino(char *line, char **tetri, t_uint8 *i)
{
	if (ft_strequ(line, ""))
	{
		if (!*tetri || ft_strlen(*tetri) != 16)
			return (-1);
		ft_strdel(tetri);
		(*i)++;
		if (*i >= 26)
			return (-1);
		return (0);
	}
	if (line_check(line) == -1)
		return (-1);
	if (create_tetrimino(line, tetri) == -1)
		return (-1);
	return (0);
}

int	read_tetriminos(const int fd, t_uint16 *tetriminos, t_shape *all_shapes)
{
	t_uint8	i;
	char	*line;
	char	*tetri;

	line = 0;
	i = 0;
	tetri = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (validate_tetrimino(line, &tetri, &i) == -1
			|| add_tetrimino(tetri, tetriminos, all_shapes, i) == -1)
		{
			ft_strdel(&line);
			ft_strdel(&tetri);
			return (-1);
		}
		ft_strdel(&line);
	}
	if (!tetri || ft_strlen(tetri) != 16)
	{
		ft_strdel(&tetri);
		return (-1);
	}
	ft_strdel(&tetri);
	return (i + 1);
}
