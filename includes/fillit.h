/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:36:27 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/24 16:22:35 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# define ASSERT(cond) ((cond) ? 0 : error_print())
# define MAT(x, y) ((y)*4 + (x))

# include "libft.h"
# include <sys/types.h>

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_tetromino
{
	int		id;
	int		x;
	int		y;
	int		width;
	int		height;
	char	matrix[16];
}				t_tetromino;

void			print_tetromino(t_tetromino *t);
void			error_print();
t_list			*load_tetros(int fd);
void			matrix_move_up(t_tetromino *tetro);
void			matrix_move_left(t_tetromino *tetro);
void			print_list(t_list *elem);
int				solve(t_list *tetros);
void			generate_answer(char *board, t_list *tetros, int size);

#endif
