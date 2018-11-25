/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:25:24 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/21 20:39:11 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **lst, t_list *node)
{
	t_list	*traverse;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = node;
		return ;
	}
	traverse = *lst;
	while (traverse->next)
		traverse = traverse->next;
	traverse->next = node;
	node->prev = traverse;
}
