/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:51:32 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/21 15:34:40 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 서식지정자의 길이를 반환하는 함수
*/
size_t		fmt_spf_len(char *format)
{
	size_t	len;

	len = 1;
	while (*format++)
	{
		len++;
		if (ft_strchr("cspdiuxX%", *format))
			return (len);
	}
	return (0);
}

/*
** 서식지정자의 각 원소를 추출하는 함수, 반환값은 각 원소에 대한 (% ~ cspdiuxX%) 실제로 출력한 길이
*/
size_t		ft_parser(va_list ap, char *format)
{
	t_all	all;

	all.flag = check_flag(++format);
	all.width = check_width(format += all.flag.idx);
	all.prec = check_prec(format += all.width.idx);
	all.type = check_type(format += all.prec.idx);
	if (all.type.c)
		return (ft_printf_char(ap, all));
	else if (all.type.s)
		return (ft_printf_str(ap, all));
	else if (all.type.p)
		return (ft_printf_ptr(ap, all));
	else
		return (ft_printf_nbr(ap, all));
	return (0);
}

/*
** idx : 서식 지정자의 인덱스
** rtn : 실제 출력하는 문자의 개수
** 반환값은 실제로 출력한 모든 문자의 개수
*/
size_t		ft_check_fmt(va_list ap, char *format)
{
	size_t	rtn;
	size_t	idx;

	rtn = 0;
	idx = 0;
	if (!format)
		return (rtn);
	while (format[idx])
	{
		if (format[idx] != '%')
		{
			ft_putchar_fd(format[idx++], 1);
			rtn++;
		}
		else
		{
			rtn += (int)ft_parser(ap, &format[idx]);
			idx += (int)fmt_spf_len(&format[idx]);
		}
	}
	return (rtn);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rtn;

	rtn = 0;
	va_start(ap, format);
	rtn = (int)ft_check_fmt(ap, (char*)format);
	va_end(ap);
	return (rtn);
}
