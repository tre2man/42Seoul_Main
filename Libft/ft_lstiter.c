/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:40:39 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/11 16:44:58 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*temp;

	temp = lst;
	if (lst)
	{
		while (temp)
		{
			f(temp->content);
			temp = temp->next;
		}
	}
}
