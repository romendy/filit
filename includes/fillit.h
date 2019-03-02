/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouachek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:15:15 by mouachek          #+#    #+#             */
/*   Updated: 2019/03/01 12:15:21 by mouachek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1000
# define NB_BLOCK 4
# define CHECK_CHAR(C) ((C == '\n' || C == '#' || C == '.') ? 1 : 0)
# define MAP(i, j) (map[tetrominos[i].block[j].x][tetrominos[i].block[j].y])
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct			s_file
{
	int				i;
	int				j;
	int				k;
	int				nb_pts;
	int				nb_sharps;
	int				nb_endl;
	int				nb_pieces;
	int				nb_link;
	int				size;
}						t_file;

typedef struct			s_block
{
	int			x;
	int			y;
}						t_block;

typedef	struct			s_tetris
{
	char				letter;
	struct s_block		block[4];
}						t_tetris;

int						ft_get_file(int fd, char **file);
t_file					*ft_reader(char **file);
int						ft_check_file(t_file *fi, char **file);
char					**ft_split_piece(char **file, t_file *fi);
int						ft_check_tetrominos(char **split, t_file *fi);
t_tetris				*ft_create_tetrominos_array(char **split, t_file *fi);
t_tetris				*ft_convert_to_relative(t_tetris *tetrominos,
		t_file *fi);
void					ft_solve(t_tetris *tetrominos, t_file *fi);
int						ft_calcul_min_map(int nb);
char					**ft_create_map(int map_size);
int						ft_place_recursive(char **map, t_tetris *tetrominos,
		t_file *fi, int nb_tetrominos);
void					ft_map_destruct(char **map, int map_size);
void					ft_print_map(char **array, int map_size);
int						ft_check_available(char **map, t_tetris tetrominos,
		int map_size, int pos);
void					ft_put_tetrominos(char **map, t_tetris tetrominos,
		int map_size, int pos);
void					ft_unput_tetrominos(char **map, t_tetris tetrominos,
		int size, int pos);
#endif
