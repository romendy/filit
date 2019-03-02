/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_assignments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouachek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:20:20 by mouachek          #+#    #+#             */
/*   Updated: 2019/03/01 12:20:24 by mouachek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris		ft_tetrominos_construct(char letter, t_block *block)
{
	int			i;
	t_tetris	tetrominos;

	tetrominos.letter = letter;
	i = 0;
	while (i < NB_BLOCK)
	{
		tetrominos.block[i] = block[i];
		i++;
	}
	return (tetrominos);
}

t_block			ft_block_c(int x, int y)
{
	t_block		block;

	block.x = x;
	block.y = y;
	return (block);
}

t_tetris		*ft_create_tetrominos_array(char **split, t_file *fi)
{
	t_block		block[4];
	t_tetris	*tetro;

	if (!(tetro = (t_tetris*)malloc(sizeof(t_tetris) * (fi->nb_pieces + 1))))
		return (NULL);
	fi->i = 0;
	fi->nb_pieces = 0;
	while (split[fi->i])
	{
		fi->j = 0;
		fi->k = 0;
		while (split[fi->i][fi->j])
		{
			if (split[fi->i][fi->j] == '#')
			{
				if (fi->i == 0)
					block[fi->k++] = ft_block_c((fi->j / 5), (fi->j % 5));
				else
					block[fi->k++] = ft_block_c((fi->j / 5), ((fi->j % 5) - 1));
			}
			fi->j++;
		}
		tetro[fi->nb_pieces++] = ft_tetrominos_construct('A' + fi->i++, block);
	}
	return (tetro);
}

t_tetris		*ft_convert_to_relative(t_tetris *tetrominos, t_file *fi)
{
	int i;
	int j;
	int first_sharp_x;
	int first_sharp_y;

	i = 0;
	while (i < fi->nb_pieces)
	{
		first_sharp_x = tetrominos[i].block[0].x;
		first_sharp_y = tetrominos[i].block[0].y;
		j = 0;
		while (j < NB_BLOCK)
		{
			tetrominos[i].block[j].x = tetrominos[i].block[j].x - first_sharp_x;
			tetrominos[i].block[j].y = tetrominos[i].block[j].y - first_sharp_y;
			j++;
		}
		i++;
	}
	return (tetrominos);
}
