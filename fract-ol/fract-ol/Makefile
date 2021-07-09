# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 13:58:22 by namwkim           #+#    #+#              #
#    Updated: 2021/07/09 13:51:02 by namwkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= main.c mandelbrot.c julia.c utils.c complex.c
OBJS		= $(SRCS:.c=.o)

RM			= rm -rf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -O3 -lmlx -framework OpenGl -framework AppKit

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) $(SRCS) -o $(NAME) $(MLXFLAGS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) $(LIBFT_LIB)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all fclean clean re
