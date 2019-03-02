/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:49:58 by romendy           #+#    #+#             */
/*   Updated: 2018/12/06 09:53:51 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void *, size_t))
{
	if (lst && *lst)
	{
		(*del)((*lst)->content, (*lst)->content_size);
		free(*lst);
		*lst = NULL;
	}
}
