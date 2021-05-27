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

int				get_next_line(int fd, char **line)
{
	static char	*save;
	char		str[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, str, BUFFER_SIZE)) > 0)
	{
		str[BUFFER_SIZE] = '\0';
		save = ft_strjoin(save, str);
		temp = ft_inchar(save, '\n');
		if (temp)
		{
			*temp = '\0';
			*line = save;
			save = temp + 1;
			break ;
		}
	}
	if (!size)
	{
		str[BUFFER_SIZE] = '\0';
		save = ft_strjoin(save, str);
		*line = save;
	}
	return (size);
}

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];
	
	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
	j = 1;
}
