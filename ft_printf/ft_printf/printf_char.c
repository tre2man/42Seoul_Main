/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:17:51 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/28 20:37:15 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				printf_char(char c, t_info *info)
{
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	else if (!info->minus)
		print_empty(' ', info->width - 1);
	else
		ft_putchar_fd(c, 1);
	if (info->minus)
		print_empty(' ', info->width - 1);
	if (info->width > 1)
		return (info->width);
	else
		return (1);
}