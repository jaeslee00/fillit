/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:00:19 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/07 19:24:31 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char*)s1)[index] != ((unsigned char*)s2)[index])
			return (((unsigned char*)s1)[index] - ((unsigned char*)s2)[index]);
		index++;
	}
	return (0);
}
