/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:17:20 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/30 11:26:24 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len_int(t_lld n)
{
	t_lld	i;
	int		rtn;

	i = 1;
	rtn = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		rtn++;
	}
	while (n / i)
	{
		i *= 10;
		rtn++;
	}
	return (rtn);
}

static int	putnbr_base10(t_info *info, t_lld num, int prec)
{
	int			rtn;

	if (!info->prec && !num)
		return (0);
	rtn = 1;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		rtn++;
		num *= -1;
	}
	if (prec)
	{
		print_empty('0', prec);
		prec = 0;
	}
	if (num > 9)
		rtn += putnbr_base10(info, num / 10, prec);
	ft_putchar_fd(BASE_D[num % 10], 1);
	return (rtn);
}

static void	check_info(int i, int len, t_info *info, int *prec)
{
	*prec = info->prec;
	if (*prec > len && i >= 0)
		*prec -= len;
	else if ((*prec > (len - 1)) && (i < 0))
		*prec -= (len - 1);
	else
		*prec = 0;
	if ((info->width > (*prec + len)) && (!len))
		info->width -= *prec;
	else if (info->width > (*prec + len))
		info->width -= (*prec + len);
	else
		info->width = 0;
	if ((info->prec == -1) && (info->zero) && !(info->minus))
	{
		*prec = info->width;
		info->width = 0;
	}
}

int	printf_int(int i, t_info *info)
{
	int			len;
	int			rtn;
	int			prec;

	rtn = 0;
	len = num_len_int(i);
	if (!info->prec && !i)
		len = 0;
	check_info(i, len, info, &prec);
	if (!info->minus)
		print_empty(' ', info->width);
	rtn = putnbr_base10(info, i, prec);
	if (info->minus)
		print_empty(' ', info->width);
	rtn += info->width + prec;
	return (rtn);
}
