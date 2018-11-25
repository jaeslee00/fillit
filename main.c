/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:23:39 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/24 16:22:54 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	error_print(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	free_tetro(void *a, size_t b)
{
	free(a);
	(void)b;
}

int		main(int argc, char **argv)
{
	int		fd;
	int		size;
	char	*answer;
	t_list	*tetro_list;

	if (argc != 2)
		ft_putstr("Usage: fillit tetrominos_file\n");
	else
	{
		ASSERT((fd = open(argv[1], O_RDONLY)) >= 0);
		tetro_list = load_tetros(fd);
		ASSERT(close(fd) == 0);
		size = solve(tetro_list);
		answer = ft_strnew(size * (size + 1));
		ASSERT(answer);
		ft_memset(answer, '.', size * (size + 1));
		generate_answer(answer, tetro_list, size);
		ft_putstr(answer);
		free(answer);
		ft_lstdel(&tetro_list, free_tetro);
	}
	return (0);
}
