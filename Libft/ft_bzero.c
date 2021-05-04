/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:23:53 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/03 16:30:06 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_bzero(void *s, unsigned int n)
{
	char *a;

	a = (char *)s;
	while (n--)
		*a++ = 0;
}

