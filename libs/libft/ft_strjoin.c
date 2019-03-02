/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 02:40:25 by romendy           #+#    #+#             */
/*   Updated: 2018/12/04 00:11:29 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;
	char	*n1;

	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	n = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (n == NULL)
		return (NULL);
	n1 = n;
	while (*s1 != '\0')
		*n1++ = *s1++;
	while (*s2 != '\0')
		*n1++ = *s2++;
	*n1 = '\0';
	return (n);
}
