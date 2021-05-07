/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:02:09 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 18:50:12 by namwkim          ###   ########.fr       */
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
	return ("");
}
