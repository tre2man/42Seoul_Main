/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:09:03 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/25 22:14:54 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#include <stdio.h>
#define BASE_X "0123456789ABCDEF"
#define BASE_x "0123456789abcdef"
#define BASE_D "0123456789"
#define FORMAT "cspiduxX%"

typedef unsigned long long	t_ulld;
typedef long long int		t_lld;

typedef struct				s_info
{
	int						minus;
	int						zero;
	int						width;
	int						prec;
	char					type;
	int						base;
	int						pct;
}							t_info;

/*
** ft_printf.c
*/
int							ft_printf(const char *format, ...);

/*
** ft_printf_xxx.c
*/
int							printf_char(va_list ap, t_info *info, char *format);
int							printf_str(va_list ap, t_info *info);
int							printf_hex(va_list ap, t_info *info);
int							printf_ptr(va_list ap, t_info *info);
int							printf_nbr(va_list ap, t_info *info);

/*
** utils1.c
*/
void						init_info(t_info *info);
void						print_empty(char c, int len);
int							num_len_int(t_lld n);
int							num_len_hex(t_ulld n);
t_lld						format_len(char *format);

#endif