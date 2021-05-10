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
	char *s1 = "lorem ipsum dolor sit amet";
    char *s2 = malloc(15);
	char dest[15];
	int i = 0;
	
	memset(s2,0,15);
	memset(s2,'r',6);
	ft_putstr_fd(s2, 1);
	ft_putstr_fd("\n", 1);
	ft_strlcpy(s2, s1, 0);
	ft_putstr_fd(s2, 1);
}