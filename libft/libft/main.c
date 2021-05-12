/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:45:49 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/10 12:44:44 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char	*s1 = "99999999999999999999";
	char	*s2 = "";
	ft_putnbr_fd(ft_atoi(s1), 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(atoi(s1), 1);
}