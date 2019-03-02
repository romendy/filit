# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouachek <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 12:23:52 by mouachek          #+#    #+#              #
#    Updated: 2019/03/01 12:23:55 by mouachek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : re fclean clean all

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror 
LIBFT= libs/libft
libfta= libs/libft/libft.a

SRCS = srcs/handle_file.c 
SRCS += srcs/handle_tetris.c 
SRCS += srcs/main.c 
SRCS += srcs/handle_map.c 
SRCS += srcs/points_assignments.c 
SRCS += srcs/backtrack.c 

OBJS = ${SRCS:.c=.o}

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		$(CC) $(FLAGS) $(SRCS) $(libfta) -o $(NAME)

all : $(NAME)

clean :
			rm -rf $(OBJS)
			$(MAKE) -C $(LIBFT) clean

fclean : clean
		rm -rf $(NAME)
		$(MAKE) -C $(LIBFT) fclean

re : fclean all
