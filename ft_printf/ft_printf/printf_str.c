/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:16:45 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/29 13:03:27 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				printf_str(char *str, t_info *info)
{
	int			len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if ((info->prec >= 0) && (len > info->prec))
		len = info->prec;
	if (!info->minus)
		print_empty(' ', info->width - len);
	write(1, str, len);
	if (info->minus)
		print_empty(' ', info->width - len);
	if (info->width < len)
		return (len);
	else
		return (info->width);
}
