# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 19:48:04 by namwkim           #+#    #+#              #
#    Updated: 2022/02/01 16:52:53 by namwkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFT		=	libft
LIBFT_LIB	=	libft.a

SRCS		=	stack_node.c stack_utils.c stack_func.c \
				tree.c \
				main.c \
				error.c \
				validator.c
OBJS		=	$(SRCS:.c=.o)

RM			=	rm -rf
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -O3

$(NAME)		:	$(OBJS)
				make -C $(LIBFT)
				$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) $(SRCS) -o $(NAME)

all			:	$(NAME)

fclean		:	clean
				$(RM) $(NAME)

clean		:
				$(RM) $(OBJS)
				make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all fclean clean re