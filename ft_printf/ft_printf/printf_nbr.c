/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 23:19:39 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/19 23:20:00 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** d,i,u,x(1, 2) 
*/
size_t			ft_printf_int(va_list ap, t_all all)
{
	/* 정밀도, 플래그, 폭 순서대로 탐색 */
	int			num;
	int			width;
	int			prec;
	int			len;

	prec = all.prec.num;
	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		all.flag.bar = 1;
	}
	if (all.prec.star)
		prec = va_arg(ap, int);
	num = va_arg(ap, int);
	/* 상태 개판임. 하나씩 정리해야 할듯 */
}
