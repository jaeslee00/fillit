/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:12:50 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/12 16:17:05 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define NODE_BUFF(n) ((t_filebuffer*)((n)->content))
# define CURR_PTR(n) (NODE_BUFF(n)->text_buffer + NODE_BUFF(n)->index)

# include <sys/types.h>

typedef struct	s_filebuffer
{
	int		fd;
	char	*text_buffer;
	ssize_t	index;
	ssize_t	size;
}				t_filebuffer;

int				get_next_line(const int fd, char **line);

#endif
