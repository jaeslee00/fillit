/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:26:19 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/09 04:43:52 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*tmp_node;

	if (alst)
	{
		node = *alst;
		while (node)
		{
			del(node->content, node->content_size);
			tmp_node = node;
			node = node->next;
			free(tmp_node);
		}
		*alst = NULL;
	}
}
