/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:26:46 by romendy           #+#    #+#             */
/*   Updated: 2019/02/28 10:31:59 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_solve(t_tetris *tetrominos, t_file *fi)
{
	char	**map;

	fi->size = ft_calcul_min_map(fi->nb_pieces * 4);
	map = ft_create_map(fi->size);
	while (ft_place_recursive(map, tetrominos, fi, 0) == 0)
	{
		ft_map_destruct(map, fi->size);
		free(map);
		fi->size++;
		map = ft_create_map(fi->size);
	}
	ft_print_map(map, fi->size);
	ft_map_destruct(map, fi->size);
	free(map);
}

int		ft_place_recursive(char **map, t_tetris *tetrominos, t_file *fi,
int nb_tetrominos)
{
	int		i;

	if (nb_tetrominos == fi->nb_pieces)
		return (1);
	i = 0;
	while (i < (fi->size * fi->size))
	{
		if (ft_check_available(map, tetrominos[nb_tetrominos], fi->size, i))
		{
			ft_put_tetrominos(map, tetrominos[nb_tetrominos], fi->size, i);
			if (ft_place_recursive(map, tetrominos, fi, nb_tetrominos + 1))
				return (1);
			ft_unput_tetrominos(map, tetrominos[nb_tetrominos], fi->size, i);
		}
		i++;
	}
	return (0);
}

int		ft_check_available(char **map, t_tetris tetrominos, int map_size,
int pos)
{
	int			i;
	t_block		current;
	t_block		next;

	current.x = (pos / map_size);
	current.y = (pos % map_size);
	i = 0;
	while (i < NB_BLOCK)
	{
		next.x = (tetrominos.block[i].x + current.x);
		next.y = (tetrominos.block[i].y + current.y);
		if (next.x >= map_size || next.y >= map_size || next.x < 0 ||
				next.y < 0 || map[next.x][next.y] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_tetrominos(char **map, t_tetris tetrominos, int map_size,
int pos)
{
	int			i;
	t_block		current;
	t_block		next;

	current.x = (pos / map_size);
	current.y = (pos % map_size);
	i = 0;
	while (i < NB_BLOCK)
	{
		next.x = (tetrominos.block[i].x + current.x);
		next.y = (tetrominos.block[i].y + current.y);
		map[next.x][next.y] = tetrominos.letter;
		i++;
	}
}

void	ft_unput_tetrominos(char **map, t_tetris tetrominos, int map_size,
int pos)
{
	int			i;
	t_block		current;
	t_block		next;

	current.x = (pos / map_size);
	current.y = (pos % map_size);
	i = 0;
	while (i < NB_BLOCK)
	{
		next.x = (tetrominos.block[i].x + current.x);
		next.y = (tetrominos.block[i].y + current.y);
		map[next.x][next.y] = '.';
		i++;
	}
}
