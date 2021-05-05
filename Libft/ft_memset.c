/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:38:48 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 14:13:50 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				*ft_memset(void *s, int c, unsigned int n)
{
	char			*a;
	unsigned int	i;

	a = (char *)s;
	i = 0;
	while (n--)
		*a++ = c;
	return (s);
}
