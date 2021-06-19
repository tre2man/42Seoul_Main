/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:11:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/19 17:12:30 by namwoo           ###   ########.fr       */
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

static void	ft_putnbr_rec(t_lld n, int num, int fd, int pf, int len)
{
	int		input;
	char	out;

	input = (int)(n % num);
	if (input < 0)
		input *= -1;
	if (input < 10)
		out = input + '0';
	else if (pf == 2)
		out = input + 55;
	else
		out = input + 87;
	if ((n > num - 1) && (len))
		ft_putnbr_rec(n / num, num, fd, pf, len - 1);
	ft_putchar_fd(out, 1);
}

/*
** n : 출력숫자, num : 진수, fd, pf : 접두사, len : 출력할 길이
** pf = 0 : 접두사x, pf = 1 : 접두사 소문자, pf = 2 : 접두사 대문자
*/
void		ft_putnbr_len_fd(t_lld n, int num, int fd, int pf, int len)
{
	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	if (pf == 1)
		ft_putstr_fd("0x", 1);
	else if (pf == 2)
		ft_putstr_fd("0X", 1);
	if (!n)
		ft_putstr_fd("0", 1);
	else
		ft_putnbr_rec(n, num, fd, pf, len);
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