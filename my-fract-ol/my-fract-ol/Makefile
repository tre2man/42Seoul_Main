# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namwookim <namwookim@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 13:58:22 by namwkim           #+#    #+#              #
#    Updated: 2021/08/15 21:56:18 by namwookim        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= main.c mandelbrot.c julia.c ship.c utils.c complex.c
OBJS		= $(SRCS:.c=.o)

RM			= rm -rf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3
MLXLIB		= minilibx_opengl
MLXFLAGS	= -L$(MLXLIB) -lmlx -framework OpenGl -framework AppKit

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	make -C $(MLXLIB)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) $(SRCS) -o $(NAME) $(MLXFLAGS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make clean -C $(MLXLIB)

clean :
	$(RM) $(OBJS)
	make clean -C $(MLXLIB)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all fclean clean re
