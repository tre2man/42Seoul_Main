/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:17:51 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/25 12:41:40 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				printf_char(va_list ap, t_info *info, char *format)
{
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	if (!info->minus)
		print_empty(' ', info->width - 1);
	if (*format == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd(va_arg(ap, int), 1);
	if (info->minus)
		print_empty(' ', info->width - 1);
	if (info->width > 1)
		return (info->width);
	else
		return (1);
}