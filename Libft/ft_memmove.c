/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:46:45 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 15:33:28 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char		*destemp;
	const char	*srctemp;

	destemp = dest;
	srctemp = src;
	if (dest > src)
	{
		destemp += n;
		srctemp += n;
		while (n--)
			*--destemp = *--srctemp;
	}
	else
	{
		while (n--)
			*destemp++ = *srctemp++;
	}
	return (dest);
}
