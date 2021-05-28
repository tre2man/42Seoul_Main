/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:20:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/21 17:16:13 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

/*
** get_next_line.c
*/
int			get_next_line(int fd, char **line);

/*
** get_next_line_utils.c
*/
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_inchar(char *s, char c);
char		*ft_strdup(const char *s1);

#endif

