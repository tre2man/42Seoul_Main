/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:49:26 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/29 19:53:19 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		num_len_base(unsigned int n, int base)
{
	int		rtn;

	rtn = 1;
	if (n > (unsigned int)(base - 1))
		rtn += num_len_base(n / base, base);
	return (rtn);
}

static int		putnbr_base(t_info *info, unsigned int num)
{
	int			rtn;

	if (!info->prec && !num)
		return (0);
	rtn = 1;
	if (info->type == 'u' && num > 9)
		rtn += putnbr_base(info, num / 10);
	else if (num > 15)
		rtn += putnbr_base(info, num / 16);
	if (info->type == 'x')
		ft_putchar_fd(BASE_SX[num % 16], 1);
	else if (info->type == 'X')
		ft_putchar_fd(BASE_X[num % 16], 1);
	else
		ft_putchar_fd(BASE_D[num % 10], 1);
	return (rtn);
}

static void		check_info(int len, t_info *info, int *prec)
{
	*prec = info->prec;
	if (*prec > len)
		*prec -= len;
	else
		*prec = 0;
	if ((info->width > (*prec + len)) && (!len))
		info->width -= *prec;
	else if (info->width > (*prec + len))
		info->width -= (*prec + len);
	else
		info->width = 0;
}

int				printf_uint(unsigned int i, t_info *info)
{
	int			len;
	int			rtn;
	int			prec;

	rtn = 0;
	if (!info->prec && !i)
		len = 0;
	else if (info->type == 'u')
		len = num_len_base(i, 10);
	else
		len = num_len_base(i, 16);
	check_info(len, info, &prec);
	if (info->zero && (info->prec == -1) && !(info->minus))
		print_empty('0', info->width);
	else if (!info->minus)
		print_empty(' ', info->width);
	print_empty('0', prec);
	rtn = putnbr_base(info, i);
	if (info->minus)
		print_empty(' ', info->width);
	rtn += info->width + prec;
	return (rtn);
}
