/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:23:47 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 16:51:03 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*a;

	i = 0;
	while (s1[i])
		i++;
	a = malloc(i);
	i = 0;
	while (*s1)
		a[i++] = *s1++;
	a[i] = s1[i];
	return (a);
}
