/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:42:36 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/14 18:09:30 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_char(va_list ap, t_all all)
{
	char		c;
	
	c = va_arg(ap, char);
	/* 정밀도, 플래그, 폭 순서대로 탐색 */
	ft_putchar_fd(c, 1);
}

void			ft_printf_str(va_list ap, t_all all)
{
	
}

void			ft_printf_int(va_list ap, t_all all)
{
	
}