/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:20:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/17 16:06:47 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
** get_next_line.c
*/
int			get_next_line(int fd, char **line);

/*
** get_next_line_utils.c
*/
char		*ft_beforestr(char *str);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_newstrlen(char *s);
size_t		ft_strlen(char *str);

#endif

