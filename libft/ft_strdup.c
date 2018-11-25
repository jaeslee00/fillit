/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:38:48 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/07 17:17:07 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy)
		ft_strcpy(copy, s1);
	return (copy);
}
