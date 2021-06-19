/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 23:18:43 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/19 23:18:59 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** i : *인자 들어올때 저장
** rtn : 반환할 실제 출력될 문자열의 길이
*/
size_t			ft_printf_char(va_list ap, t_all all)
{
	char		c;
	int			width;

	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		all.flag.bar = 1;
	}
	c = (char)va_arg(ap, int);
	if (!all.flag.bar)
		print_empty(all.flag.zero, width - 1);
	ft_putchar_fd(c, 1);
	if (all.flag.bar)
		print_empty(all.flag.zero, width - 1);
	if (width > 1)
		return (width);
	else
		return (1);
}
