/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouachek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:16:17 by mouachek          #+#    #+#             */
/*   Updated: 2019/03/01 12:16:21 by mouachek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_calcul_min_map(int nb)
{
	int i;

	i = 1;
	if (nb == 1)
		return (2);
	while ((i * i) < nb)
		i++;
	return (i);
}

char		**ft_create_map(int map_size)
{
	int		i;
	int		j;
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*) * (map_size + 1))))
		return (NULL);
	ft_bzero(map, map_size + 1);
	i = 0;
	while (i < map_size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (map_size + 1))))
			return (NULL);
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		ft_map_destruct(char **map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
}

void		ft_print_map(char **array, int map_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			ft_putchar(array[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
