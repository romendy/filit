/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 02:34:03 by romendy           #+#    #+#             */
/*   Updated: 2018/11/29 02:39:00 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	if (s)
	{
		str = ft_strnew(len);
		while (str == NULL)
			return (NULL);
		s = s + start;
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}
