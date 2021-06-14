/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:42:36 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/14 20:50:18 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** i : *인자 들어올때 저장
** rtn : 반환할 실제 출력될 문자열의 길이
*/
size_t ft_printf_char(va_list ap, t_all all)
{
	char c;
	int i;
	int rtn;

	rtn = 0;
	i = 0;
	if (all.flag.star)
		i = va_arg(ap, int);
	c = va_arg(ap, char);
	if (all.flag.bar && all.flag.zero)
		print_empty('0', i - 1);
	else if (all.flag.bar && !all.flag.zero)
		print_empty(' ', i - 1);
	ft_putchar_fd(c, 1);
	if (!all.flag.bar && all.flag.zero)
		print_empty('0', i - 1);
	if (!all.flag.bar && !all.flag.zero)
		print_empty(' ', i - 1);
}

size_t ft_printf_str(va_list ap, t_all all)
{
	char *str;
	int i;
	int idx;

	idx = 0;
	i = 0;
	if (all.flag.star)
		i = va_arg(ap, int);
	str = va_arg(ap, char*);
	if (all.flag.star)
	{
		if (all.flag.bar && all.flag.zero)
			print_empty('0', i - 1);
		else if (all.flag.bar && !all.flag.zero)
			print_empty(' ', i - 1);
		ft_putchar_fd(c, 1);
		if (!all.flag.bar && all.flag.zero)
			print_empty('0', i - 1);
		if (!all.flag.bar && !all.flag.zero)
			print_empty(' ', i - 1);
	}
}

size_t ft_printf_int(va_list ap, t_all all)
{
	/* 정밀도, 플래그, 폭 순서대로 탐색 */
}

void print_empty(char c, int i)
{
	int idx;

	i = 0;
	while (idx < i)
	{
		ft_putchar_fd(&c, 1);
		idx++;
	}
}