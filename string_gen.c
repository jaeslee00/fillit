/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:12:29 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/24 16:28:55 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	newlines(char *board, int size)
{
	int index;

	index = size;
	while (index <= size * (size + 1))
	{
		board[index] = '\n';
		index += size + 1;
	}
}

void		generate_answer(char *board, t_list *tetros, int size)
{
	t_tetromino	*tetro;
	t_coord		coord;

	while (tetros != NULL)
	{
		tetro = (t_tetromino*)tetros->content;
		coord.y = 0;
		while (coord.y < tetro->height)
		{
			coord.x = 0;
			while (coord.x < tetro->width)
			{
				if (tetro->matrix[MAT(coord.x, coord.y)] == 1)
					board[coord.x + tetro->x
						+ (size + 1) * (coord.y + tetro->y)] = tetro->id + 'A';
				coord.x++;
			}
			coord.y++;
		}
		tetros = tetros->next;
	}
	newlines(board, size);
}
