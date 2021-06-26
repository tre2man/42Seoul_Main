/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:51:07 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/25 22:06:59 by namwoo           ###   ########.fr       */
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
	info->base = 10;
	info->pct = 0;
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

int			num_len_int(t_lld n)
{
	t_lld	i;
	int		rtn;

	i = 1;
	rtn = 0;
	if (!n)
		return (1);
	if (n < 0)
		n *= -1;
	while (n / i)
	{
		i *= 10;
		rtn++;
	}	
	return (rtn);
}

int			num_len_hex(t_ulld n)
{
	t_lld	i;
	int		rtn;

	i = 1;
	rtn = 0;
	if (!n)
		return (1);
	while (n / i)
	{
		i *= 16;
		rtn++;
	}
	return (rtn);
}

t_lld			format_len(char *format)
{
	int			rtn;

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