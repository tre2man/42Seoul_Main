/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:35:56 by namwoo            #+#    #+#             */
/*   Updated: 2021/07/16 00:11:04 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_argv(char **argv)
{
	int				pid;
	int				idx;
	unsigned char	shift;
	int				byte;

	pid = atoi(argv[1]);
	idx = -1;
	while (argv[2][++idx])
	{
		shift = 1;
		byte = -1;
		while (++byte < BYTE)
		{
			if (argv[2][idx] & (shift << byte))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 3 || !argv[2])
	{
		printf("error\n");
		return (0);
	}
	else
	{
		while(argv[1][i])
		{
			if (!isdigit(argv[1][i++]))
			{
				printf("error\n");
				return (0);
			}
		}
	}
	send_argv(argv);
	return (0);
}