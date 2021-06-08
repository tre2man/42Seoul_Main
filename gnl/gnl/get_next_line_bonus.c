/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:19:39 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/08 23:48:46 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*get_next(char *save)
{
	int			i;
	char		*ans;

	if (!save)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
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
	while (save[len] && save[len] != '\n')
		len++;
	if (!(ans = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memset(ans, 0, sizeof(char) * (len + 1));
	while (save[idx] && save[idx] != '\n')
	{
		ans[idx] = save[idx];
		idx++;
	}
	return (ans);
}

int				free_error(char *str)
{
	free(str);
	return (-1);
}


int				in_newline(char *save)
{
	if (!save)
		return (0);
	while (*save)
	{
		if (*save == '\n')
			return (1);
		save++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *save[OPEN_MAX];
	char		*buffer;
	int			rread;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	rread = 1;
	while (!in_newline(save) && rread != 0)
	{
		ft_memset(buffer, 0, sizeof(char) * (BUFFER_SIZE + 1));
		if ((rread = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (free_error(buffer));
		if (!(save[fd] = ft_strjoin_(save[fd], buffer)))
			return (free_error(buffer));
	}
	free(buffer);
	*line = get_now(save[fd]);
	save[fd] = get_next(save[fd]);
	if (!rread)
		return (0);
	return (1);
}
