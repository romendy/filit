/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:41:31 by romendy           #+#    #+#             */
/*   Updated: 2018/12/06 10:14:54 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	if (lst && *lst)
	{
		(*del)((*lst)->content, (*lst)->content_size);
		if ((*lst)->next)
			ft_lstdel(&(*lst)->next, del);
		free(*lst);
		*lst = NULL;
	}
}
