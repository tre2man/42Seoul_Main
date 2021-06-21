/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:51:08 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/21 17:01:04 by namwkim          ###   ########.fr       */
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
	if (prec > len)
		len = prec;
	if (!all.flag.bar)
		print_empty(all.flag.zero, width - len);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
	}
	print_empty('0', prec - ft_nbr_len(num, 10));
	ft_putnbr_len_fd(num, 10, 1, 0, len);
	if (all.flag.bar)
		print_empty(all.flag.zero, width - len);
	if (len > width)
		return ((size_t)(len));
	else
		return ((size_t)(width));
}
