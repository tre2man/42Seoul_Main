/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:11:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/22 19:13:00 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_empty(char c, int i)
{
	int		idx;
	char	prt;

	idx = 0;
	prt = ' ';
	if (c)
		prt = c;
	while (idx < i)
	{
		ft_putchar_fd(prt, 1);
		idx++;
	}
}

/*
** n : 숫자, num : 진수
*/
int			ft_nbr_len(t_lld n, int num)
{
	t_lld	i;
	int		rtn;

	i = 1;
	rtn = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		rtn++;
		n *= -1;
	}
	while (n / i)
	{
		i *= num;
		rtn++;
	}	
	return (rtn);
}