/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwookim <namwookim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:35:56 by namwoo            #+#    #+#             */
/*   Updated: 2021/07/25 02:12:25 by namwookim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_argv(char **argv)
{
	int				pid;
	int				idx;
	int				byte;

	pid = ft_atoi(argv[1]);
	if (pid < 2 || pid > PID_MAX)
	{
		ft_putstr_fd("INCORRECT PID!", 2);
		exit(0);
	}
	idx = -1;
	while (argv[2][++idx])
	{
		byte = -1;
		while (++byte < BYTE)
		{
			if (argv[2][idx] & (1 << byte))
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
		ft_putstr_fd("TYPE CORRECT ARGV!\n", 2);
		return (0);
	}
	else
	{
		while(argv[1][i])
		{
			if (!ft_isdigit(argv[1][i++]))
			{
				ft_putstr_fd("PID FAULT!\n", 2);
				return (0);
			}
		}
	}
	send_argv(argv);
	return (0);
}
