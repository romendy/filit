/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:26:58 by romendy           #+#    #+#             */
/*   Updated: 2019/02/28 10:32:04 by romendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_file		*ft_file_constructor(void)
{
	t_file	*fi;

	if (!(fi = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	fi->i = 0;
	fi->j = 0;
	fi->k = 0;
	fi->nb_pts = 0;
	fi->nb_sharps = 0;
	fi->nb_endl = 0;
	fi->nb_pieces = 0;
	fi->nb_link = 0;
	fi->size = 0;
	return (fi);
}

int			ft_get_file(int fd, char **file)
{
	ssize_t		ret;
	char		buffer[BUFF_SIZE + 1];
	char		*s;
	char		*str;

	s = NULL;
	if ((str = ft_strnew(-1)) == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		s = ft_strjoin(str, buffer);
		free(str);
		str = s;
	}
	if (s == NULL)
		return (-1);
	*file = s;
	return (0);
}

int			ft_check_file(t_file *fi, char **file)
{
	int len;

	len = 0;
	while ((*file)[len])
	{
		if ((*file)[len] == '.')
			fi->nb_pts++;
		len++;
	}
	if (fi->nb_sharps % 4 != 0 ||
		(fi->nb_endl + 1) / 5 != fi->nb_pieces)
		return (-1);
	if ((*file)[len - 1] == '\n' && (*file)[len - 2] == '\n')
		return (-1);
	if (fi->nb_pieces == 0 || fi->nb_pieces > 26)
		return (-1);
	if (fi->nb_pts != fi->nb_pieces * 12)
		return (-1);
	return (0);
}

t_file		*ft_reader(char **file)
{
	static int	i = 0;
	static int	j = 0;
	t_file		*fi;

	fi = ft_file_constructor();
	while ((*file)[i])
	{
		if (CHECK_CHAR((*file)[i]) == 0)
			return (NULL);
		if ((*file)[i] == '\n')
		{
			if (j == 1 && fi->nb_endl % 5 != 4)
				return (NULL);
			j = 0;
			fi->nb_endl++;
		}
		if ((*file)[i] == '#')
			fi->nb_sharps++;
		i++;
		j++;
	}
	fi->nb_pieces = (fi->nb_sharps / 4);
	if (ft_check_file(fi, file) == -1)
		return (NULL);
	return (fi);
}
