/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:32:42 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/21 20:46:00 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrem(t_list **lst, const void *ref, t_comparison cmp)
{
	t_list	*traverse;
	t_list	*last;

	if (!lst || !cmp || !(*lst))
		return (NULL);
	if (!cmp(ref, (*lst)->content))
	{
		traverse = *lst;
		*lst = traverse->next;
		return (traverse);
	}
	last = (*lst);
	traverse = (*lst)->next;
	while (traverse)
	{
		if (!cmp(ref, traverse->content))
		{
			last->next = traverse->next;
			traverse->next->prev = last;
			return (traverse);
		}
		last = traverse;
		traverse = traverse->next;
	}
	return (NULL);
}
