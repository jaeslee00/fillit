/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:33:59 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/25 15:56:32 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "get_next_line.h"
#include <stdlib.h>

static void		init_tetro(t_tetromino *tetro)
{
	static int id_gen = 0;

	tetro->id = id_gen++;
	ASSERT(id_gen > 0);
	tetro->x = 4;
	tetro->y = 4;
	tetro->width = 0;
	tetro->height = 0;
	ft_bzero(tetro->matrix, sizeof(char) * 4 * 4);
}

static void		process_line(char *line, t_tetromino *tetro, int cycle)
{
	size_t index;

	index = 0;
	if (cycle < 4)
	{
		ASSERT(ft_strlen(line) == 4
				&& (line[0] == '.' || line[0] == '#')
				&& (line[1] == '.' || line[1] == '#')
				&& (line[2] == '.' || line[2] == '#')
				&& (line[3] == '.' || line[3] == '#'));
		while (index < 4)
		{
			if (line[index] == '#')
				tetro->matrix[MAT(index, cycle)] = 1;
			index++;
		}
	}
	else
		ASSERT(ft_strlen(line) == 0);
}

static int		count_connects(t_tetromino *tetro)
{
	int connects;
	int horiz;
	int vert;

	connects = 0;
	vert = 0;
	while (vert < 4)
	{
		horiz = 0;
		while (horiz < 4)
		{
			if (tetro->matrix[MAT(horiz, vert)])
			{
				connects +=
					(horiz > 0 ? tetro->matrix[MAT(horiz - 1, vert)] : 0)
					+ (horiz < 3 ? tetro->matrix[MAT(horiz + 1, vert)] : 0)
					+ (vert > 0 ? tetro->matrix[MAT(horiz, vert - 1)] : 0)
					+ (vert < 3 ? tetro->matrix[MAT(horiz, vert + 1)] : 0);
			}
			horiz++;
		}
		vert++;
	}
	return (connects);
}

static void		process_tetro(t_tetromino *tetro)
{
	t_coord local;
	int		count;

	count = 0;
	local.y = 0;
	while (local.y < 4)
	{
		local.x = 0;
		while (local.x < 4)
		{
			if (tetro->matrix[MAT(local.x, local.y)])
			{
				tetro->x = ft_min(tetro->x, local.x);
				tetro->y = ft_min(tetro->y, local.y);
				tetro->width = ft_max(tetro->width, local.x + 1);
				tetro->height = ft_max(tetro->height, local.y + 1);
				count++;
			}
			local.x++;
		}
		local.y++;
	}
	ASSERT(count == 4 && count_connects(tetro) >= 6);
	matrix_move_up(tetro);
	matrix_move_left(tetro);
}

t_list			*load_tetros(int fd)
{
	t_list		*tetro_list;
	t_tetromino tetro;
	char		*line;
	int			cycle;
	int			input_ret;

	cycle = 0;
	tetro_list = NULL;
	while ((input_ret = get_next_line(fd, &line)) > 0)
	{
		if (cycle == 0)
			init_tetro(&tetro);
		process_line(line, &tetro, cycle);
		if (cycle == 3)
		{
			process_tetro(&tetro);
			ft_lstappend(&tetro_list, ft_lstnew(&tetro, sizeof(t_tetromino)));
		}
		free(line);
		cycle = (cycle + 1) % 5;
	}
	free(line);
	ASSERT(input_ret == 0 && cycle == 4);
	return (tetro_list);
}
