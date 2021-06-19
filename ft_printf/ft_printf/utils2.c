/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:42:36 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/19 16:15:21 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** i : *인자 들어올때 저장
** rtn : 반환할 실제 출력될 문자열의 길이
*/
size_t			ft_printf_char(va_list ap, t_all all)
{
	char		c;
	int			width;

	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		all.flag.bar = 1;
	}
	c = (char)va_arg(ap, int);
	if (!all.flag.bar)
		print_empty(all.flag.zero, width - 1);
	ft_putchar_fd(c, 1);
	if (all.flag.bar)
		print_empty(all.flag.zero, width - 1);
	if (width > 1)
		return (width);
	else
		return (1);
}

/*
** 줄넘어감
*/
size_t			ft_printf_str(va_list ap, t_all all)
{
	char		*str;
	int			width;
	int			prec;
	int			len;

	prec = all.prec.num;
	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		all.flag.bar = 1;
	}
	if (all.prec.star)
		prec = va_arg(ap, int);
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if ((len > prec) && (all.prec.dot == 1))
		len = prec;
	if (!all.flag.bar)
		print_empty(all.flag.zero, width - len);
	write(1, str, len);
	if (all.flag.bar)
		print_empty(all.flag.zero, width - len);
	if (width - len < 0)
		return (len);
	else
		return (width);
}	

size_t			ft_printf_ptr(va_list ap, t_all all)
{
	void		*ptr;
	int			len;
	int			width;

	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		all.flag.bar = 1;
	}
	ptr = (void*)va_arg(ap, char*);
	len = ft_nbr_len((t_lld)ptr, 16);
	if (!all.flag.bar)
		print_empty(' ', width - len - 2);
	ft_putnbr_len_fd((t_lld)ptr, 16, 1, 1, len);
	if (all.flag.bar)
		print_empty(' ', width - len - 2);
	if (width > len + 2)
		return ((size_t)(width));
	else
		return ((size_t)(len + 2));
}

/*
** d,i,u,x(1, 2) 
*/
size_t			ft_printf_int(va_list ap, t_all all)
{
	/* 정밀도, 플래그, 폭 순서대로 탐색 */
	int			num;
	int			width;
	int			prec;
	int			len;

	prec = all.prec.num;
	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		all.flag.bar = 1;
	}
	if (all.prec.star)
		prec = va_arg(ap, int);
	num = va_arg(ap, int);
	/* 상태 개판임. 하나씩 정리해야 할듯 */
}
