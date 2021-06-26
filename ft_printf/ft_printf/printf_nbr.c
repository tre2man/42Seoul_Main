/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:17:20 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/26 10:51:50 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putnbr_base16(t_info *info, t_ulld num)
{
	int			rtn;

	rtn = 1;
	if ((info->prec != 0) && (num))
		rtn = 0;
	if (info->type == 'p')
	{
		ft_putstr_fd("0x", 1);
		rtn += 2;
		info->type = 0;
	}
	if ((info->prec) && (info->prec - num_len_hex(num) >= 0))
	{
		print_empty('0', info->prec - num_len_hex(num));
		rtn += (info->prec - num_len_hex(num));
		info->prec = 0;
	}
	if (num > 15)
		rtn += putnbr_base16(info, num / 16);
	if ((info->type == 'X') && (info->prec != 0) && (num))
		ft_putchar_fd(BASE_X[num % 16], 1);
	else if ((info->prec != 0) && (num))
		ft_putchar_fd(BASE_x[num % 16], 1);
	return (rtn);
}

static int		putnbr_base10(t_info *info, t_lld num)
{
	int			rtn;

	rtn = 0;
	if ((info->prec) && (info->prec - num_len_hex(num) >= 0))
	{
		print_empty('0', info->prec - num_len_int(num));
		rtn += (info->prec - num_len_int(num));
		info->prec = 0;
	}
	if (num > 9)
		putnbr_base10(info, num / 10);
	ft_putchar_fd(BASE_D[num % 10], 1);
}

static int		int_control(t_info *info, t_lld num)
{
	int			rtn;

	rtn = 0;
	if (info->prec >= 0)
	{
		info->width = info->prec;
		info->width = 0;
	}
	if (!(info->minus) && (info->prec >= 0))
		print_empty(' ', info->width - info->prec);
	putnbr_base10(info, num);
	if (info->minus&& (info->prec >= 0))
		print_empty(' ', info->width - info->prec);
	return (rtn);
}

int				printf_nbr(va_list ap, t_info *info)
{
	int			len;
	int			rtn;

	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}

	info->base = 10;
	rtn = int_control(info, (t_lld)va_arg(ap, int));
	return (rtn);
}