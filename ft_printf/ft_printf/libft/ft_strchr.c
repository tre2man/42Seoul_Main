/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:02:09 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/10 12:19:59 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;
	unsigned char	*a;

	a = (unsigned char *)s;
	i = (unsigned char)c;
	while (*a)
	{
		if (*a == i)
			return ((char *)a);
		a++;
	}
	if (*a == i)
		return ((char *)a);
	return (0);
}
