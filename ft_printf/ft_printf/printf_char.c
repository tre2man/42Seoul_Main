/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:17:51 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/29 21:55:44 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				printf_char(char c, t_info *info)
{
	int			rtn;

	rtn = 1;
	if (info->width > 0)
		info->width -= 1;
	if (info->zero && !(info->minus))
		print_empty('0', info->width);
	else if (!info->minus)
		print_empty(' ', info->width);
	ft_putchar_fd(c, 1);
	if (info->minus)
		print_empty(' ', info->width);
	rtn += info->width;
	return (rtn);
}
