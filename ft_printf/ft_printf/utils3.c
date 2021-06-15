/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:11:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/15 19:01:31 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_empty(char c, int i)
{
	int		idx;

	idx = 0;
	while (idx < i)
	{
		ft_putchar_fd(c, 1);
		idx++;
	}
}

static void	ft_putnbr_rec(lld n, int fd, int lower)
{
	int		input;
	char	out;

	input = (int)(n % 16);
	if (input < 0)
		input *= -1;
	if (input < 10)
		out = input + '0';
	else if (!lower)
		out = input + 55;
	else
		out = input + 87;
	if (n > 15 || n < -15)
		ft_putnbr_rec(n / 16, fd, lower);
	write(fd, &out, 1);
}

void		ft_putnbr_hexa_fd(lld n, int fd, int lower)
{
	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	if (lower)
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0X", 1);
	ft_putnbr_rec(n, fd, lower);
}

int			ft_hexanbr_len(lld n)
{
	lld		i;
	int		rtn;

	i = 1;
	rtn = 0;
	while (n / i)
	{
		i *= 16;
		rtn++;
	}
	return (rtn);
}