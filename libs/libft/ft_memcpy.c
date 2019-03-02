/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:25:27 by romendy           #+#    #+#             */
/*   Updated: 2018/12/03 02:02:49 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tdst;
	const char	*tsrc;

	tdst = dest;
	tsrc = src;
	while (n-- > 0)
		*tdst++ = *tsrc++;
	return (dest);
}
