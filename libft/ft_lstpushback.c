/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:09:42 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/23 18:18:00 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpushback(t_list **lst, void *content, size_t size)
{
	t_list	*elem;
	t_list	*new;

	if (!lst)
		return (0);
	elem = *lst;
	while (elem && elem->next)
		elem = elem->next;
	if (!(new = ft_lstnew(content, size)))
		return (0);
	if (*lst)
		elem->next = new;
	else
		*lst = new;
	return (1);
}
