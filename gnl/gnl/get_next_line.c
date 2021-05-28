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

char			*ft_strsave(char *save, char *buff)
{
	char		*ans;

	ans = ft_strjoin(save, buff);
	printf("save : %s\n", save);
	return (ans);
}

int				get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	char		*tempsave;
	char		*temp;
	ssize_t		size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		tempsave = ft_strsave(save, buff);
		save = ft_strdup(tempsave);
		if (tempsave)
			free(tempsave);
		temp = ft_inchar(save, '\n');
		if (temp)
		{
			*temp = '\0';
			*line = save;
			save = temp + 1;
			break ;
		}
		ft_memset(buff, 0, sizeof(buff));
	}
	if (!size)
		*line = save;
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

	if (!(fd = open("42TESTERS-GNL/files/alphabet", O_RDONLY)))
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
	system("leaks a.out");
}