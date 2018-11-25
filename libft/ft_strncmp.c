/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:16:36 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/07 15:19:10 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	while (index < n && s1[index] && s1[index] == s2[index])
		index++;
	if (index == n)
		return (0);
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
