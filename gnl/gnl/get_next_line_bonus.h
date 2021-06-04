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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** get_next_line_bonus.c
*/
int			get_next_line(int fd, char **line);

/*
** get_next_line_utils_bonus.c
*/
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(char const *s);
char		*ft_strjoin_(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, char *src, size_t size);

#endif
