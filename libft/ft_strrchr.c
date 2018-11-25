/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:36:21 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/07 15:01:22 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*last_found;

	index = 0;
	last_found = NULL;
	while (s[index])
	{
		if (s[index] == (char)c)
			last_found = ((char*)&s[index]);
		index++;
	}
	if (s[index] == (char)c)
		last_found = ((char*)&s[index]);
	return (last_found);
}
