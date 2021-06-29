/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:35:11 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/29 19:53:05 by namwkim          ###   ########.fr       */
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
	ft_putchar_fd(BASE_SX[num % 16], 1);
	return (rtn);
}

int				printf_ptr(void *ptr, t_info *info)
{
	int			rtn;
	t_ulld		num;

	num = (t_ulld)ptr;
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
