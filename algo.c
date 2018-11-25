/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 03:35:24 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/25 14:23:54 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static int	check_pair(t_tetromino *curr, t_tetromino *prev)
{
	t_coord	curr_offset;
	t_coord	prev_offset;

	curr_offset.y = 0;
	while (curr_offset.y < 4)
	{
		curr_offset.x = 0;
		while (curr_offset.x < 4)
		{
			prev_offset.x = curr_offset.x + curr->x - prev->x;
			prev_offset.y = curr_offset.y + curr->y - prev->y;
			if (prev_offset.x >= 0 && prev_offset.x < 4
			&& prev_offset.y >= 0 && prev_offset.y < 4
			&& (curr->matrix[MAT(curr_offset.x, curr_offset.y)] == 1
			&& prev->matrix[MAT(prev_offset.x, prev_offset.y)] == 1))
				return (0);
			curr_offset.x++;
		}
		curr_offset.y++;
	}
	return (1);
}

static int	check_conflicts(t_list *placed)
{
	t_tetromino *curr;
	t_tetromino *prev;
	t_list		*traverse;

	traverse = placed->prev;
	curr = (t_tetromino*)placed->content;
	while (traverse)
	{
		prev = (t_tetromino*)traverse->content;
		if (!check_pair(curr, prev))
			return (0);
		traverse = traverse->prev;
	}
	return (1);
}

static int	solve_recursive(t_list *tetros, int size)
{
	t_tetromino *current;

	current = (t_tetromino*)tetros->content;
	current->y = 0;
	while (current->y + current->height <= size)
	{
		current->x = 0;
		while (current->x + current->width <= size)
		{
			if (check_conflicts(tetros))
			{
				if (!tetros->next)
					return (1);
				else if (solve_recursive(tetros->next, size))
					return (1);
			}
			current->x++;
		}
		current->y++;
	}
	return (0);
}

int			solve(t_list *tetros)
{
	int		size;

	size = 2;
	while (!solve_recursive(tetros, size))
		size++;
	return (size);
}
