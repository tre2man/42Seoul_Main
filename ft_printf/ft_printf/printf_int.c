/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:17:20 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/27 16:07:29 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putnbr_base10(t_info *info, t_lld num)
{
	int			rtn;

	/* 정밀도가 정의되어 있으면서 0일 경우 */
	if (info->isprec == 2)
		return (0);
	rtn = 1;
	if (num < 0)
		ft_putchar_fd('-', 1);
	if (info->isprec)
	{
		print_empty('0', info->prec);
		rtn += info->prec;
		info->prec = 0;
	}
	if (num < 0)
	{
		num *= -1;
		rtn++;
	}
	if (num > 9)
		rtn += putnbr_base10(info, num / 10);
	ft_putchar_fd(BASE_x[num % 10], 1);
	return (rtn);
}

static void		check_info(int *num, int *len, t_info *info)
{	
	/* 정밀도가 정의되어 있고 정밀도가 0인 동시에 num이 0인 경우 */
	if (info->isprec == 1 && !info->prec && !*num)
	{
		info->isprec = 2;
		*len = 0;
	}
	/* 정밀도가 실제 길이보다 긴 경우 */
	if (info->prec > *len)
		info->prec -= *len;
	else if (info->prec > 0)
		info->prec = 0;
	/* 폭이 실제 길이 + 정밀도 보다 긴 경우 */
	if ((info->width > (info->prec + *len)))
		info->width -= (info->prec + *len);
	else
		info->width = 0;
	/* 정밀도 정의되지 않고, minus 플래그가 없고, 0있는 경우 */
	if (!info->isprec && info->zero && !info->minus)
	{
		info->isprec = 1;
		if (info->width > 0)
			info->prec = info->width;
		else
			info->prec = -info->width;
		if (*num < 0)
			info->prec--;
		info->width = 0;
	}
}

int				printf_int(va_list ap, t_info *info)
{
	int			len;
	int			rtn;
	int			num;

	info->base = 10;
	num = (va_arg(ap, int));
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	rtn = 0;
	len = num_len_int((t_lld)num);
	check_info(&num, &len, info);
	if(!info->minus)
		print_empty(' ', info->width - (num < 0));
	rtn += putnbr_base10(info, num);
	if (info->minus)
		print_empty(' ', info->width - (num < 0));
	if ((info->width - (num < 0)) >= 0)
		rtn += info->width - (num < 0);
	return (rtn);
}