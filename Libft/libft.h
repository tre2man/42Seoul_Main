/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:24:09 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 19:41:29 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>

/* Part1 - Libc functions */
int				ft_atoi(const char *str);
void			ft_bzero(void *s, unsigned int n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, unsigned int n);
void			*ft_memcpy(void	 *dst, void *src, unsigned int n);
void			*ft_memccpy(void *dst, void *src, int c, unsigned int n);
void			*ft_memmove(void *dest, const void *src, unsigned int n);
void			*ft_memset(void *s, int c, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize);
unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);
unsigned int	ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strnstr(char *haystack, char *needle, unsigned int len);
int				ft_tolower(int c);
int				ft_toupper(int c);
/* use malloc */
void			*ft_calloc(unsigned int count, unsigned int size);
char			*ft_strdup(const char *s1);


/* Part2 - Additional functions */
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *s2);

#endif
