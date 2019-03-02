/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:55:11 by romendy           #+#    #+#             */
/*   Updated: 2018/12/03 02:08:09 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st1;
	unsigned char *st2;

	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	while (n > 0 && *st1 == *st2)
	{
		st1++;
		st2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*st1 - *st2);
}
