/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:19:39 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/17 16:10:45 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	*line = ft_beforestr(*line);
	return ((int)read(fd, line, BUFFER_SIZE));
}

int main()
{
	int fd;
	int i=0;
	char *line = 0;
	
	if (!(fd = open("gnlTester/files/41_with_nl", O_RDONLY)))
	{
		printf("Error");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("**\n");
		printf("|%s\n",line);
		free(line);
	}
	printf("|%s\n",line);
	free(line);
	close(fd);
	return (0);
}