/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:57:50 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/24 14:42:26 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	matrix_line_clear(t_tetromino *tetro)
{
	int		index;
	int		used;

	index = 0;
	used = 0;
	while (index < 4)
	{
		used |= tetro->matrix[MAT(index, 0)];
		index++;
	}
	return (!used);
}

static int	matrix_column_clear(t_tetromino *tetro)
{
	int		index;
	int		used;

	index = 0;
	used = 0;
	while (index < 4)
	{
		used |= tetro->matrix[MAT(0, index)];
		index++;
	}
	return (!used);
}

void		matrix_move_up(t_tetromino *tetro)
{
	int	horiz;
	int vert;

	while (matrix_line_clear(tetro))
	{
		vert = 0;
		while (vert < 4)
		{
			horiz = 0;
			while (horiz < 4)
			{
				tetro->matrix[MAT(horiz, vert)] =
					(vert < 3) ? tetro->matrix[MAT(horiz, vert + 1)] : 0;
				horiz++;
			}
			vert++;
		}
	}
	tetro->height -= tetro->y;
	tetro->y = 0;
}

void		matrix_move_left(t_tetromino *tetro)
{
	int horiz;
	int vert;

	while (matrix_column_clear(tetro))
	{
		horiz = 0;
		while (horiz < 4)
		{
			vert = 0;
			while (vert < 4)
			{
				tetro->matrix[MAT(horiz, vert)] =
					(horiz < 3) ? tetro->matrix[MAT(horiz + 1, vert)] : 0;
				vert++;
			}
			horiz++;
		}
	}
	tetro->width -= tetro->x;
	tetro->x = 0;
}
