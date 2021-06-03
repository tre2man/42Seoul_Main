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

char			*get_next(char *save)
{
	int			i;
	char		*ans;

	if (!save)
		return (0);
	while(save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(ans = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	ft_strlcpy(ans, save + i + 1, ft_strlen(save + i + 1) + 1);
	free(save);
	return (ans);
}

char			*get_now(char *save)
{
	int			len;
	int			idx;
	char		*ans;

	if (!save)
		return (0);
	len = 0;
	idx = 0;
	while(save[len] && save[len] != '\n')
		len++;
	if (!(ans = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memset(ans, 0, sizeof(char) * (len + 1));
	while(save[idx] && save[idx] != '\n')
	{
		ans[idx] = save[idx];
		idx++;
	}
	return (ans);
}

int				in_newline(char *save)
{
	if (!save)
		return (0);
	while(*save)
	{
		if (*save == '\n')
			return (1);
		save++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *save;
	char		*buffer;
	int			rread;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	rread = 1;
	while (!in_newline(save) && rread != 0)
	{
		ft_memset(buffer, 0, sizeof(char) * (BUFFER_SIZE + 1));
		rread = read(fd, buffer, BUFFER_SIZE);
		if (rread == -1)
		{
			free(buffer);
			return (-1);
		}
		save = ft_strjoin_(save, buffer);
	}
	free(buffer);
	*line = get_now(save);
	save = get_next(save);
	if (!rread)
		return (0);
	return (1);
}
