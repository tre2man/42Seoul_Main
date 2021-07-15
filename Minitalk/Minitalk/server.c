/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:46:19 by namwoo            #+#    #+#             */
/*   Updated: 2021/07/16 00:05:48 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_char(int sig)
{
	static int 			byte;
	static unsigned int	c;

	if (sig == SIGUSR1)
		c |= 1 << byte;
	if (++byte == 8)
	{
		write(1, &c, 1);
		byte = 0;
		c = 0;
	}
}

int main(void)
{
	printf("pid is %d\n", getpid());
	signal(SIGUSR1, print_char);
	signal(SIGUSR2, print_char);
	while(1)
	{
		;
	}
}
