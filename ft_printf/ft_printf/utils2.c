/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:42:36 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/15 19:13:23 by namwkim          ###   ########.fr       */
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
	c = va_arg(ap, char);
	if (!all.flag.bar)
		print_empty(' ', width - 1);
	ft_putchar_fd(c, 1);
	if (all.flag.bar)
		print_empty(' ', width - 1);
	if (width > 1)
		return (width);
	else
		return (1);
}

size_t			ft_printf_str(va_list ap, t_all all)
{
	char		*str;
	int			i;
	int			len;
	int			idx;

	idx = 0;
	i = 0;
	if (all.flag.star)
		i = va_arg(ap, int);
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	/* 작성 필요 */
}

size_t			ft_printf_ptr(va_list ap, t_all all)
{
	void		*ptr;
	int			len;
	int			width;

	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	ptr = (void*)va_arg(ap, char*);
	len = ft_hexanbr_len((lld)ptr);
	if (!all.flag.bar)
		print_empty(' ', width - len - 2);
	ft_putnbr_hexa_fd(ptr, 1, 1);
	if (all.flag.bar)
		print_empty(' ', width - len - 2);
	if (len + 2 > width)
		return ((size_t)(len + 2));
	else
		return ((size_t)(width));
}

size_t ft_printf_int(va_list ap, t_all all)
{
	/* 정밀도, 플래그, 폭 순서대로 탐색 */
}
