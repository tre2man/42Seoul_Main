/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:49:14 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/18 18:58:31 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_save(char *s)
{
	static char	*save;
	size_t		blen;

	blen = ft_strlen(s);
	save = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	
}

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
