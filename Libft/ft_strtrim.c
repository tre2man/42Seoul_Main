/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:46:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/06 18:13:29 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*ans;

	if (!s1 || !set)
		return (0);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[rear] && ft_strchr(set, s1[rear - 1]) && front < rear)
		rear--;
	ans = (char*)malloc(sizeof(char) * (rear - front + 1));
	if (ans)
		ft_strlcpy(ans, (char*)(s1 + front), rear - front + 1);
	return (ans);
}
