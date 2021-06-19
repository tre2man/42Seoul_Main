/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 23:19:25 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/20 00:29:25 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr_len(t_ulld n, int num)
{
	t_ulld	i;
	int		rtn;

	i = 1;
	rtn = 0;
	if (!n)
		return (1);
	while (n / i)
	{
		i *= num;
		rtn++;
	}	
	return (rtn);
}

static void		ft_putnbr_rec(t_ulld n, int num, int fd, int pf, int len)
{
	int		input;
	char	out;

	input = (int)(n % num);
	if (input < 0)
		input *= -1;
	if (input < 10)
		out = input + '0';
	else if (pf == 2)
		out = input + 55;
	else
		out = input + 87;
	if ((n > num - 1) && (len))
		ft_putnbr_rec(n / num, num, fd, pf, len - 1);
	ft_putchar_fd(out, 1);
}

/*
** n : 출력숫자, num : 진수, fd, pf : 접두사, len : 출력할 길이
** pf = 0 : 접두사x, pf = 1 : 접두사 소문자, pf = 2 : 접두사 대문자
*/
static void		ft_putptr_len_fd(t_ulld n, int num, int fd, int pf, int len)
{
	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	if (pf == 1)
		ft_putstr_fd("0x", 1);
	else if (pf == 2)
		ft_putstr_fd("0X", 1);
	if (!n)
		ft_putstr_fd("0", 1);
	else
		ft_putnbr_rec(n, num, fd, pf, len);
}

size_t			ft_printf_ptr(va_list ap, t_all all)
{
	t_ulld      ptr;
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
	ptr = (t_ulld)va_arg(ap, char*);
	len = ft_ptr_len(ptr, 16);
	if (!all.flag.bar)
		print_empty(' ', width - len - 2);
	ft_putptr_len_fd(ptr, 16, 1, 1, len);
	if (all.flag.bar)
		print_empty(' ', width - len - 2);
	if (width > len + 2)
		return ((size_t)(width));
	else
		return ((size_t)(len + 2));
}
