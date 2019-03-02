/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouachek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:18:50 by mouachek          #+#    #+#             */
/*   Updated: 2019/03/01 12:18:54 by mouachek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_free_all(char **file, char **split,
		t_file *fi, t_tetris *tetrominos)
{
	int i;

	free(*file);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	free(tetrominos);
	free(fi);
}

int			main(int argc, const char *argv[])
{
	char		*file;
	char		**split;
	t_file		*fi;
	t_tetris	*tetrominos_array;

	if (argc == 2)
	{
		if ((ft_get_file(open(argv[1], O_RDONLY), &file)) == -1
			|| ((fi = ft_reader(&file)) == NULL)
			|| ((split = ft_split_piece(&file, fi)) == NULL)
			|| (ft_check_tetrominos(split, fi) == -1)
			|| ((tetrominos_array = ft_create_tetrominos_array(split, fi))
				== NULL)
			|| ((tetrominos_array = ft_convert_to_relative(tetrominos_array,
			fi)) == NULL))
		{
			ft_putstr("error\n");
			return (-1);
		}
		ft_solve(tetrominos_array, fi);
		ft_free_all(&file, split, fi, tetrominos_array);
	}
	else
		ft_putstr("usage : ./fillit [nom_de_fichier]");
	return (0);
}
