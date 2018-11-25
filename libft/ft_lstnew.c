/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:58:18 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/21 20:45:18 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (content)
	{
		ret->content = malloc(content_size);
		if (!ret->content)
			return (NULL);
		ft_memcpy(ret->content, content, content_size);
	}
	else
		ret->content = NULL;
	ret->content_size = content ? content_size : 0;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}
