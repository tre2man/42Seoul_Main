/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:51:07 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/29 15:15:15 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 'd';
}

void		print_empty(char c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

t_lld		format_len(char *format)
{
	int		rtn;

	if (!format)
		return (0);
	rtn = 2;
	format++;
	while (*format && !ft_strchr(FORMAT, *format))
	{
		format++;
		rtn++;
	}
	return (rtn);
}
