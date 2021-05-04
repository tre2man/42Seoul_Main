/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:21:22 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 14:32:59 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int			ft_strlcpy(char *restrict dst, const char *restrict src, unsigned int dstsize)
{
	unsigned int		i;

	i = 0;
	while(dst[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

