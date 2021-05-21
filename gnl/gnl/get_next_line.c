/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:19:39 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/21 17:49:40 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	char	*str;
	ssize_t	size;
	
	str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while(1)
	{
		size = read(fd, str, BUFFER_SIZE);
		str[BUFFER_SIZE] = '\0';
		*line = ft_save(str);
		if (ft_strrchr(str, '\n'))
			break;
	}
	/*
	size = read(fd, str, BUFFER_SIZE);
	str[BUFFER_SIZE] = '\0';
	*line = str;
	printf("%s\n", str);
	*/
	return (fd);
}

int main()
{
	int				fd;
	int				i;
	int				j;
	char			*line = 0;
	char			*lineadress[66];
	
	j = 1;
	
	if (!(fd = open("alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		//lineadress[j - 1] = line;
		j++;
		if (j > 500)
			break;
	}
	//printf("|%s\n", line);
	free(line);
	close(fd);
}
