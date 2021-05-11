/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:25:33 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/11 16:27:37 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	**temp;

	temp = lst;
	while (*(temp->next))
		*temp = *(temp->next);
	temp->next = new;
}
