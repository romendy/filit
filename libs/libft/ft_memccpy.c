/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:31:10 by romendy           #+#    #+#             */
/*   Updated: 2018/11/22 19:17:46 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*tdst;
	char	*tsrc;

	tdst = (char*)dest;
	tsrc = (char*)src;
	while (n--)
	{
		*(tdst++) = *tsrc;
		if (*(tsrc++) == (char)c)
			return (tdst);
	}
	return (NULL);
}
