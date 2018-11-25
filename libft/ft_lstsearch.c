/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:31:59 by aamadori          #+#    #+#             */
/*   Updated: 2018/11/11 15:45:04 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, const void *ref, t_comparison cmp)
{
	while (lst)
	{
		if (!cmp(lst->content, ref))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
