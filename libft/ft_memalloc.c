/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:15:28 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/07 17:19:21 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	index;

	index = 0;
	ptr = malloc(size);
	while (ptr && index < size)
	{
		((char*)ptr)[index] = 0;
		index++;
	}
	return (ptr);
}
