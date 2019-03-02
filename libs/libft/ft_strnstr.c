/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:49:16 by romendy           #+#    #+#             */
/*   Updated: 2018/12/03 01:00:05 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t			len;
	unsigned int	i;
	unsigned int	tmp;

	len = ft_strlen(find);
	if (len == 0)
		return (char*)(str);
	i = 0;
	while (str[i] != '\0' && (len + i) <= n)
	{
		tmp = 0;
		while (find[tmp] == str[tmp + i])
		{
			if (tmp == (len - 1))
				return ((char*)str + i);
			tmp++;
		}
		i++;
	}
	return (NULL);
}
