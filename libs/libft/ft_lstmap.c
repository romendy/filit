/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:05:06 by romendy           #+#    #+#             */
/*   Updated: 2018/12/06 10:25:23 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*link;
	t_list	*first;

	if (!f)
		return (NULL);
	new = (*f)(lst);
	first = ft_lstnew(new->content, new->content_size);
	link = first;
	lst = lst->next;
	while (lst)
	{
		new = (*f)(lst);
		link->next = ft_lstnew(new->content, new->content_size);
		link = link->next;
		lst = lst->next;
	}
	return (first);
}
