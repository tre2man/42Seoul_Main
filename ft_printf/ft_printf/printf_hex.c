/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:49:26 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/26 20:32:07 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putnbr_base16(t_info *info, t_ulld num)
{
	int			rtn;

	/* 정밀도가 정의되어 있으면서 0일 경우 */
	if ((info->isprec == 1) && (num == 0))
		return (0);
	rtn = 1;
	if (num > 15)
		rtn += putnbr_base16(info, num / 16);
	if (info->type == 'x')
		ft_putchar_fd(BASE_x[num % 16], 1);
	else
		ft_putchar_fd(BASE_X[num % 16], 1);
	return (rtn);
}

int				printf_hex(va_list ap, t_info *info)
{
	int			len;
	int			rtn;
	t_ulld		num;

	info->base = 16;
	num = (t_ulld)va_arg(ap, void*);
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	rtn = 0;
	len = num_len_hex(num);
	//printf("[%d %d %d]", len, info->width, info->prec);
	/* 정밀도가 정의되어 있으면서 num이 0인 경우 */
	if (info->isprec == 1 && num == 0)
		len = 0;
	/* 정밀도가 실제 길이보다 긴 경우 */
	if (info->prec > len)
		info->prec -= len;
	else if (info->prec > 0)
		info->prec = 0;
	/* 폭이 실제 길이 + 정밀도 보다 긴 경우 */
	if ((info->width > (info->prec + len)))
		info->width -= (info->prec + len);
	else
		info->width = 0;
	//printf("[%d %d %d]", len, info->width, info->prec);
	if(!info->minus)
		print_empty(' ', info->width);
	print_empty('0', info->prec);
	rtn += putnbr_base16(info, num);
	if (info->minus)
		print_empty(' ', info->width);
	if (info->prec == -1)
		info->prec = 0;
	rtn += info->width + info->prec;
	return (rtn);
}