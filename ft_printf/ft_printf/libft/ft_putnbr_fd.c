/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:44:14 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 14:18:39 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec(int n, int fd)
{
	int		input;
	char	out;

	input = n % 10;
	if (input < 0)
		input *= -1;
	out = input + '0';
	if (n > 9 || n < -9)
		ft_rec(n / 10, fd);
	write(fd, &out, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	ft_rec(n, fd);
}
