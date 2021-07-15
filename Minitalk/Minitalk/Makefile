# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 22:34:12 by namwoo            #+#    #+#              #
#    Updated: 2021/07/15 22:45:12 by namwoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
SERVER		= server
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./client.c ./server.c
OBJS		= ./client.o ./server.o
SRCS_BONUS	= .
OBJS_BONUS	= .
INCS		= .
RM			= rm -rf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

ifdef IS_BONUS
	NOW_OBJS = $(OBJS_BONUS)
else
	NOW_OBJS = $(OBJS)
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) $(NOW_OBJS)

all : $(NAME)

fclean : clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

re		: fclean all

bonus	:
		IS_BONUS=1 $(MAKE)

.PHONY : all fclean clean re bonus