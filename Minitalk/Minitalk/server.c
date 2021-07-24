/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwookim <namwookim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:46:19 by namwoo            #+#    #+#             */
/*   Updated: 2021/07/25 02:12:41 by namwookim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_char(int sig)
{
	static int 			byte;
	static unsigned int	c;

	if (sig == SIGUSR1)
		c |= 1 << byte;
	if (++byte == BYTE)
	{
		write(1, &c, 1);
		byte = 0;
		c = 0;
	}
}

int main(int argc, char **argv)
{
	if (argc != 1 || argv[1])
	{
		ft_putstr_fd("PROHIBIT ARGV!", 2);
		return (0);
	}
	ft_putstr_fd("pid is", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, print_char);
	signal(SIGUSR2, print_char);
	while(1)
		pause();
	return (0);
}
