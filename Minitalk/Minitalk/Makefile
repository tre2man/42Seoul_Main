# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namwookim <namwookim@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 22:34:12 by namwoo            #+#    #+#              #
#    Updated: 2021/07/25 02:13:21 by namwookim        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
SERVER		= server
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= client.c server.c
OBJS		= $(SRCS:.c=.o)

RM			= rm -rf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3

all		: $(OBJS)
		make -C $(LIBFT)
		make $(CLIENT)
		make $(SERVER)

$(CLIENT)	:
		$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) -o $(CLIENT) client.o

$(SERVER)	:
		$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) -o $(SERVER) server.o

fclean	: clean
		$(RM) $(CLIENT) $(SERVER)

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

re		: fclean all

.PHONY	: all fclean clean re
