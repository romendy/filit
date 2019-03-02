/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:27:23 by romendy           #+#    #+#             */
/*   Updated: 2019/02/28 10:32:19 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_is_piece(char *str)
{
	if (*(str) == '\n' && *(str + 1) == '\n')
		return (1);
	return (0);
}

int			ft_count_chars(char *str)
{
	int i;

	i = 0;
	while (str[i] && !ft_is_piece(&str[i]))
		i++;
	return (i);
}

char		**ft_split_piece(char **file, t_file *fi)
{
	int		i;
	int		j;
	char	**split;
	int		piece_count;
	int		len;

	if (!(split = (char**)malloc(sizeof(char*) * (fi->nb_pieces + 1))))
		return (NULL);
	i = 0;
	piece_count = 0;
	while (piece_count < fi->nb_pieces)
	{
		while ((*file)[i] && ft_is_piece(&((*file)[i])))
			i++;
		len = ft_count_chars(&((*file)[i]));
		if (!(split[piece_count] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		j = 0;
		while (j < len)
			split[piece_count][j++] = (*file)[i++];
		split[piece_count][j] = '\0';
		piece_count++;
	}
	split[piece_count] = 0;
	return (split);
}

int			ft_check_tetrominos(char **split, t_file *fi)
{
	fi->i = 0;
	while (split[fi->i])
	{
		fi->nb_link = 0;
		fi->j = 0;
		while (split[fi->i][fi->j])
		{
			if (split[fi->i][fi->j] == '#')
			{
				if (fi->j - 5 >= 0 && split[fi->i][fi->j - 5] == '#')
					fi->nb_link++;
				if (fi->j + 5 < 20 && split[fi->i][fi->j + 5] == '#')
					fi->nb_link++;
				if (fi->j - 1 >= 0 && split[fi->i][fi->j - 1] == '#')
					fi->nb_link++;
				if (fi->j + 1 < 20 && split[fi->i][fi->j + 1] == '#')
					fi->nb_link++;
			}
			fi->j++;
		}
		if ((fi->nb_link % 6 != 0 && fi->nb_link % 8 != 0) || fi->nb_link == 0)
			return (-1);
		fi->i++;
	}
	return (0);
}
