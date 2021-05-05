/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:33:06 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 14:17:59 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
		i++;
	while (dst[j] && j < dstsize)
		j++;
	while (src[k] && j + 1 < dstsize)
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	if (k)
		dst[j] = '\0';
	return (i + j - k);
}
