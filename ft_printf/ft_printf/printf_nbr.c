/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:51:08 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/22 19:27:47 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 정밀도, 폭 순으로 계산
*/




static void	ft_putnbr_rec(t_lld n, int num, int pf, int len)
{
	int		input;
	char	out;

	if (!len)
		return ;
	input = (int)(n % num);
	if (input < 0)
		input *= -1;
	if (input < 10)
		out = input + '0';
	if (n > num - 1)
		ft_putnbr_rec(n / num, num, pf, len - 1);
	ft_putchar_fd(out, 1);
}

/*
** n : 출력숫자, num : 진수, fd, pf : 접두사, len : 출력할 길이
** pf = 0 : 접두사x, pf = 1 : 접두사 소문자, pf = 2 : 접두사 대문자
*/
static void		ft_putnbr_len(t_lld n, int num, int prec, int pf, int len)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	print_empty('0', prec - ft_nbr_len(n, 10));
	ft_putnbr_rec(n, num, pf, len);
}


/*
** 음수 출력, 정밀도 계산, 반환값 오류
*/
size_t			ft_printf_nbr(va_list ap, t_all all)
{
	t_lld		num;
	int			len;
	int			width;
	int			prec;

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
	num = (t_lld)va_arg(ap, int);
	len = ft_nbr_len(num, 10);
	if (prec > len)
		len = prec;
	if (num < 0)
		len++;
	if (width && !prec && !all.flag.bar)
	{
		prec = width;
		width = len;
	}
	// width 출력, 플래그에 따라서 0일수도 아닐수도
	if (!all.flag.bar)
		print_empty(all.flag.zero, width - len);
	ft_putnbr_len(num, 10, prec, 0, len);
	// 뒤에서 width 출력, 0 플래그 무시
	if (all.flag.bar)
		print_empty(' ', width - len);
	if (len > width)
		return ((size_t)(len));
	else
		return ((size_t)(width));
}
