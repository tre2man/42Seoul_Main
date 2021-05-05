/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:46:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 19:19:46 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strcheck(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	char			*str;
	char			*temp;

	str = ft_strdup(s1);
	i = 0;
	while (str[i])
	{
		if (ft_strcheck((str + i), (char*)set))
		{
			temp = ft_strdup(str);
			temp[i] = '\0';
			str = ft_strjoin(temp, temp + i + ft_strlen(set));
		}
		else
			i++;
	}
	if (!ft_strcmp(s1, str))
		return (0);
	else
		return (str);
}
