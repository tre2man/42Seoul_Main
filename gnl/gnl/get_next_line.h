/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:20:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/18 18:56:16 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

/*
** get_next_line.c
*/
int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);

/*
** get_next_line_utils.c
*/
char		*ft_save(char *s);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, size_t start, size_t len);
size_t		ft_findnext(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strrchr(const char *s, int c);

#endif

