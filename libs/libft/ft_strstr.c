/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:51:43 by romendy           #+#    #+#             */
/*   Updated: 2018/12/04 02:24:08 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int len;

	len = ft_strlen(s2);
	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
