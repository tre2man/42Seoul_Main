/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:35:11 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/26 13:18:27 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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