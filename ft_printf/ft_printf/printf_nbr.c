/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:51:08 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/20 14:46:34 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 정밀도, 폭 순으로 계산
*/


/*
** 음수 출력, 정밀도 계산, 반환값 오류
*/
size_t			ft_printf_nbr(va_list ap, t_all all)
{
	t_lld		num;
	int			len;
	int			width;
	int			prec;

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
	num = (t_lld)va_arg(ap, int);
	len = ft_nbr_len(num, 10);
	if ((len > prec) && (all.prec.dot))
		len = prec;
	if (!all.flag.bar)
	{
		print_empty(' ', width - prec);
		print_empty('0', prec - len);
	}
	ft_putnbr_len_fd(num, 10, 1, 0, len);
	if (all.flag.bar)
	{	
		
		print_empty(' ', width - prec);
		print_empty('0', prec - len);
	}
	if (prec > width)
		return ((size_t)(prec));
	else
		return ((size_t)(width));
}
