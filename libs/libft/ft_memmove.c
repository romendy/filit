/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 04:26:36 by romendy           #+#    #+#             */
/*   Updated: 2018/11/30 02:30:16 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *tdst;
	char *tsrc;

	tdst = (char*)dst;
	tsrc = (char*)src;
	if (tsrc < tdst)
	{
		tsrc = tsrc + n - 1;
		tdst = tdst + n - 1;
		while (n > 0)
		{
			*tdst-- = *tsrc--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*tdst++ = *tsrc++;
			n--;
		}
	}
	return (dst);
}
