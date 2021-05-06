/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:44:14 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/06 18:46:13 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (fd < 0)
		return ;
	str = ft_itoa(n);
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
