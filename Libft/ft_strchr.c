/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:02:09 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 16:21:55 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char*)s;
	while (*a)
	{
		if (*a == (unsigned char)c)
			return (a);
		a++;
	}
	return (0);
}
