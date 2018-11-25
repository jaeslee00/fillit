/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:08:07 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/07 19:47:39 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t offset;

	offset = 0;
	while (haystack[offset])
	{
		if (!ft_strncmp(&haystack[offset], needle, ft_strlen(needle)))
			return ((char*)&haystack[offset]);
		offset++;
	}
	if (!haystack[0] && !needle[0])
		return ((char*)haystack);
	return (NULL);
}
