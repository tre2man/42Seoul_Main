/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:35:11 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/27 12:34:33 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		num_len_hex(t_ulld n)
{
	int		rtn;

	rtn = 1;
	if (n > 15)
		rtn += num_len_hex(n / 16);
	return (rtn);
}

static int		putnbr_base16(t_info *info, t_ulld num)
{
	int			rtn;

	rtn = 1;
	if (num > 15)
		rtn += putnbr_base16(info, num / 16);
	ft_putchar_fd(BASE_x[num % 16], 1);
	return (rtn);
}

int			printf_ptr(va_list ap, t_info *info)
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
	rtn = 2;
	if (!info->minus)
		print_empty(' ', info->width - num_len_hex(num) - 2);
	ft_putstr_fd("0x", 1);
	rtn += putnbr_base16(info, num);
	if (info->minus)
		print_empty(' ', info->width - num_len_hex(num) - 2);
	if (info->width - num_len_hex(num) - 2 > 0)
		rtn += (info->width - num_len_hex(num) - 2);	
	return (rtn);
}