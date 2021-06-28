/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:49:26 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/28 15:16:42 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		num_len_base(unsigned int n, int base)
{
	int		rtn;

	rtn = 1;
	if (n > (base - 1))
		rtn += num_len_base(n / base, base);
	return (rtn);
}

static int		putnbr_base(t_info *info, unsigned int num)
{
	int			rtn;

	/* 정밀도가 정의되어 있으면서 0일 경우 */
	if (info->isprec == 2)
		return (0);
	rtn = 1;
	if (info->type == 'u' && num > 9)
		rtn += putnbr_base(info, num / 10);
	else if (num > 15)
		rtn += putnbr_base(info, num / 16);
	if (info->type == 'x')
		ft_putchar_fd(BASE_x[num % 16], 1);
	else if (info->type == 'X')
		ft_putchar_fd(BASE_X[num % 16], 1);
	else
		ft_putchar_fd(BASE_D[num % 10], 1);
	return (rtn);
}

static void			check_info(unsigned int num, int *len, t_info *info)
{
	if (info->type == 'u')
		*len = num_len_base(num, 10);
	else
		*len = num_len_base(num, 16);
	/* 정밀도가 정의되어 있고 정밀도가 0인 동시에 num이 0인 경우 */
	if ((info->isprec == 1) && (!info->prec) && !num)
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
		if (info->width > 0)
			info->prec = info->width;
		else
			info->prec = -info->width;
		info->width = 0;
	}
}

int					printf_uint(va_list ap, t_info *info)
{
	int				len;
	int				rtn;
	unsigned int	num;

	info->base = 16;
	num = va_arg(ap, int);
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	rtn = 0;
	check_info(num, &len, info);
	if(!info->minus)
		print_empty(' ', info->width);
	print_empty('0', info->prec);
	rtn += putnbr_base(info, num);
	if (info->minus)
		print_empty(' ', info->width);
	if (info->prec == -1)
		info->prec = 0;
	rtn += info->width + info->prec;
	return (rtn);
}