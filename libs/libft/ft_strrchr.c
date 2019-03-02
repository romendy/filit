/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:40:57 by romendy           #+#    #+#             */
/*   Updated: 2018/12/04 00:17:48 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;

	f = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			f = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (f);
}
