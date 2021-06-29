/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:17:51 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/29 18:06:39 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_info(t_info *info, int *prec)
{
	*prec = info->prec;
	if (*prec > 1)
		*prec -= 1;
	else
		*prec = 0;
	if ((info->width > (*prec + 1)))
		info->width -= (*prec + 1);
	else
		info->width = 0;
}

int				printf_char(char c, t_info *info)
{
	int			rtn;
	int			prec;

	rtn = 1;
	info->prec = -1;
	check_info(info, &prec);
	if (info->zero && (info->prec == -1) && !(info->minus))
		print_empty('0', info->width);
	else if (!info->minus)
		print_empty(' ', info->width);
	print_empty('0', prec);
	ft_putchar_fd(c, 1);
	if (info->minus)
		print_empty(' ', info->width);
	rtn += info->width + prec;
	return (rtn);
}
